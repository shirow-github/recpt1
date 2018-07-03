/* -*- tab-width: 4; indent-tabs-mode: nil -*- */
#ifndef _RECPT1_H_
#define _RECPT1_H_

#define NUM_BSDEV       24
#define NUM_ISDB_T_DEV  24
#define CHTYPE_SATELLITE    0        /* satellite digital */
#define CHTYPE_GROUND       1        /* terrestrial digital */
#define MAX_QUEUE           8192
#define MAX_READ_SIZE       (188 * 87) /* 188*87=16356 splitter��188���饤���Ȥ���Ԥ��Ƥ���ΤǤ��ο����Ȥ���*/
#define WRITE_SIZE          (1024 * 1024 * 2)
#define TRUE                1
#define FALSE               0

#define ISDB_T_NODE_LIMIT 24        // 32:ARIB limit 24:program maximum
#define ISDB_T_SLOT_LIMIT 8

typedef struct {
    int size;
    u_char buffer[MAX_READ_SIZE];
} BUFSZ;

typedef struct {
    unsigned int in;        // ��������륤��ǥå���
    unsigned int out;        // ���˽Ф�����ǥå���
    unsigned int size;        // ���塼�Υ�����
    unsigned int num_avail;    // ������ˤʤ�� 0 �ˤʤ�
    unsigned int num_used;    // ���äݤˤʤ�� 0 �ˤʤ�
    pthread_mutex_t mutex;
    pthread_cond_t cond_avail;    // �ǡ�����������ΤȤ����ԤĤ���� cond
    pthread_cond_t cond_used;    // �ǡ��������ΤȤ����ԤĤ���� cond
    BUFSZ *buffer[1];    // �Хåե��ݥ���
} QUEUE_T;

typedef struct {
    int set_freq;    // �ºݤ�ioctl()��Ԥ���
    int type;        // �����ͥ륿����
    int add_freq;    // �ɲä�����ȿ�(BS/CS�ξ��ϥ���å��ֹ�)
    char *parm_freq;    // �ѥ�᡼���Ǽ�������
} ISDB_T_FREQ_CONV_TABLE;

#endif
