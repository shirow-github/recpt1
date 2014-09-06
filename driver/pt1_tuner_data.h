#ifndef		__PT1_TUNER_DATA_H__
#define		__PT1_TUNER_DATA_H__
/***************************************************************************/
/*                                                                         */
/***************************************************************************/
#define		PT1_MAX_ISDB_S_INIT	19			// ISDB-S ������ǡ�����
#define		PT1_MAX_ISDB_T_INIT	16			// ISDB-T ������ǡ�����
#define		PT2_MAX_ISDB_S_INIT 	18			// ISDB-S ������ǡ�����
#define		PT2_MAX_ISDB_T_INIT 	12			// ISDB-T ������ǡ�����

#define		MAX_BS_CHANNEL		36			// ���ȿ��ơ��֥��
#define		MAX_ISDB_T_CHANNEL	113			// ���ȿ��ơ��֥��(�ϥǥ�����)
#define		MAX_BS_CHANNEL_PLL_COMMAND	3	// PLL��å����뤿��Υ��ޥ�ɿ�
/***************************************************************************/
/*                                                                         */
/***************************************************************************/

/***************************************************************************/
/*                                                                         */
/***************************************************************************/
typedef	struct	_WBLOCK_BS_PLL{
	WBLOCK	*wblock[MAX_BS_CHANNEL_PLL_COMMAND] ;
}WBLOCK_BS_PLL;

/***************************************************************************/
/*                                                                         */
/***************************************************************************/
extern	WBLOCK	com_initdata;		//�����(����)
extern	WBLOCK	isdb_s_init1;		//ISDB-S��Ƭ
extern	WBLOCK	isdb_s_init21;		//ISDB-S�ǽ�
extern	WBLOCK	isdb_t_init17;		//ISDB-T�ǽ�
extern	WBLOCK	bs_pll_lock;		//ISDB-S PLL��å���ǧ
extern	WBLOCK	*isdb_s_initial_pt1[PT1_MAX_ISDB_S_INIT];
extern	WBLOCK	*isdb_t_initial_pt1[PT1_MAX_ISDB_T_INIT];
extern	WBLOCK	*isdb_s_initial_pt2[PT2_MAX_ISDB_S_INIT];
extern	WBLOCK	*isdb_t_initial_pt2[PT2_MAX_ISDB_T_INIT];
/***************************************************************************/
/* BS�ѥǡ������                                                          */
/***************************************************************************/
extern	WBLOCK_BS_PLL	bs_pll[MAX_BS_CHANNEL] ;	// ���ȿ��ơ��֥�
extern	WBLOCK	*bs_get_ts_id[(MAX_BS_TS_ID / 2)] ;	// TS-ID�����ơ��֥�
extern	WBLOCK	bs_tmcc_get_1;						// TMCC�����ơ��֥�
extern	WBLOCK	bs_tmcc_get_2;						// TMCC�����ơ��֥�
extern	WBLOCK	bs_get_ts_lock;
extern	WBLOCK	bs_set_ts_lock;
extern	WBLOCK	bs_get_slot;
extern	WBLOCK	bs_get_clock;
extern	WBLOCK	bs_get_carrir;
extern	WBLOCK	bs_get_signal1;
extern	WBLOCK	bs_get_signal2;
extern	WBLOCK	bs_get_agc;
/***************************************************************************/
/* �ϥǥ��ѥǡ������                                                      */
/***************************************************************************/
extern	WBLOCK	isdb_t_pll_base;			// �ϥǥ��Ѽ��ȿ��ơ��֥�base
extern	WBLOCK	isdb_t_pll_lock;
extern	WBLOCK_BS_PLL	isdb_t_info[MAX_ISDB_T_INFO_LEN];
extern	WBLOCK	isdb_t_check_tune;
extern	WBLOCK	isdb_t_tune_read;
extern	WBLOCK	isdb_t_tmcc_read_1;
extern	WBLOCK	isdb_t_tmcc_read_1;
extern	WBLOCK	isdb_t_signal1;
extern	WBLOCK	isdb_t_signal2;
extern	WBLOCK	isdb_t_agc2;

extern	WBLOCK	isdb_t_get_clock;
extern	WBLOCK	isdb_t_get_carrir;

/***************************************************************************/
/* �������ѥǡ������                                                      */
/***************************************************************************/
extern	WBLOCK	isdb_s_wake;
extern	WBLOCK	isdb_t_wake;
extern	WBLOCK	isdb_s_wake2;
extern	WBLOCK	isdb_t_wake2;

extern	WBLOCK	isdb_s_sleep;
extern	WBLOCK	isdb_t_sleep;

extern	ISDB_S_CH_TABLE	isdb_t_table[11];

#endif
