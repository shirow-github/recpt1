#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "decoder.h"

#ifdef HAVE_LIBARIBB25

uint8_t *_data = NULL;

decoder *
b25_startup(decoder_options *opt)
{
    decoder *dec = calloc(1, sizeof(decoder));
    int code;
    const char *err = NULL;

    dec->b25 = create_arib_std_b25();
    if(!dec->b25) {
        err = "create_arib_std_b25 failed";
        goto error;
    }

    code = dec->b25->set_multi2_round(dec->b25, opt->round);
    if(code < 0) {
        err = "set_multi2_round failed";
        goto error;
    }

    code = dec->b25->set_strip(dec->b25, opt->strip);
    if(code < 0) {
        err = "set_strip failed";
        goto error;
    }

    code = dec->b25->set_emm_proc(dec->b25, opt->emm);
    if(code < 0) {
        err = "set_emm_proc failed";
        goto error;
    }

    dec->bcas = create_b_cas_card();
    if(!dec->bcas) {
        err = "create_b_cas_card failed";
        goto error;
    }
    code = dec->bcas->init(dec->bcas);
    if(code < 0) {
        err = "bcas->init failed";
        goto error;
    }

    code = dec->b25->set_b_cas_card(dec->b25, dec->bcas);
    if(code < 0) {
        err = "set_b_cas_card failed";
        goto error;
    }

    return dec;

error:
    fprintf(stderr, "%s\n", err);
    free(dec);
    return NULL;
}

int
b25_shutdown(decoder *dec)
{
    if(_data) {
	free(_data);
	_data = NULL;
    }
    dec->b25->release(dec->b25);
    dec->bcas->release(dec->bcas);
    free(dec);

    return 0;
}

int
b25_decode(decoder *dec, ARIB_STD_B25_BUFFER *sbuf, ARIB_STD_B25_BUFFER *dbuf)
{
  int code;

  if(_data) {
	free(_data);
	_data = NULL;
  }

  ARIB_STD_B25_BUFFER buf;
  buf.data = sbuf->data;
  buf.size = sbuf->size;

  code = dec->b25->put(dec->b25, &buf);
  if(code < 0) {
      fprintf(stderr, "b25->put failed\n");
      uint8_t *p = NULL;
      dec->b25->withdraw(dec->b25, &buf);
      if(buf.size > 0) {
		p = (uint8_t *)malloc(buf.size + sbuf->size);
      }
      if(p) {
		memcpy(p, buf.data, buf.size);
		memcpy(p + buf.size, sbuf->data, sbuf->size);
		dbuf->data = p;
		dbuf->size = buf.size + sbuf->size;
		_data = p;
      }
      else {
		fprintf(stderr, "Not enough memory\n");
		dbuf->data = sbuf->data;
		dbuf->size = sbuf->size;
      }
      return code;
  }

  code = dec->b25->get(dec->b25, &buf);
  if(code < 0) {
      fprintf(stderr, "b25->get failed\n");
  }
  dbuf->data = buf.data;
  dbuf->size = buf.size;

  return code;
}

int
b25_finish(decoder *dec, ARIB_STD_B25_BUFFER *sbuf, ARIB_STD_B25_BUFFER *dbuf)
{
  int code;

  code = dec->b25->flush(dec->b25);
  if(code >= 0) {
      code = dec->b25->get(dec->b25, dbuf);
      if(code >= 0) {
		return code;
      }
      else {
		fprintf(stderr, "b25->get failed\n");
      }
  }
  else {
      fprintf(stderr, "b25->flush failed\n");
  }

  dbuf->data = sbuf->data;
  dbuf->size = sbuf->size;

  return code;
}

#else

/* functions */
decoder *b25_startup(decoder_options *opt)
{
    return NULL;
}

int b25_shutdown(decoder *dec)
{
    return 0;
}

int b25_decode(decoder *dec,
               ARIB_STD_B25_BUFFER *sbuf,
               ARIB_STD_B25_BUFFER *dbuf)
{
    return 0;
}

int b25_finish(decoder *dec,
               ARIB_STD_B25_BUFFER *sbuf,
               ARIB_STD_B25_BUFFER *dbuf)
{
    return 0;
}

#endif
