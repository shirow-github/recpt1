#ifndef		__PT1_TUNER_H__
#define		__PT1_TUNER_H__
/***************************************************************************/
/* ���塼�ʾ������                                                        */
/***************************************************************************/
// SLEEP�⡼������
enum	{
	TYPE_SLEEP,
	TYPE_WAKEUP
};

// ���塼�ʥѥ�⡼������
enum {
	BIT_TUNER,
	BIT_LNB_UP,
	BIT_LNB_DOWN,
	BIT_RESET,
	BIT_33A1,
	BIT_33A2,
	BIT_5A_,
	BIT_5A1,
	BIT_5A2
};

// LNB�ѥ����
enum{
	LNB_OFF,						// LNB OFF
	LNB_11V,						// +11 V
	LNB_15V							// +15 V
};

enum{								// �Ÿ����ϡ��ɥ������ꥻ�å�
	TUNER_POWER_OFF,				// ���ա����͡��֥�
	TUNER_POWER_ON_RESET_ENABLE,	// ���󡿥��͡��֥�
	TUNER_POWER_ON_RESET_DISABLE	// ���󡿥ǥ������֥�
};

enum {
    PT1 = 0,
    PT2,
};

/***************************************************************************/
/* ���塼�ʾ������                                                        */
/***************************************************************************/
#define		MAX_BS_TS_ID		8			// TS-ID����������
#define		MAX_ISDB_T_INFO		3			// �ϥǥ����ؾ����
#define		MAX_ISDB_T_INFO_LEN		2			// �ϥǥ����ؾ����
/***************************************************************************/
/* ISDB-S�������                                                         */
/***************************************************************************/
typedef struct  _ISDB_S_CH_TABLE{
	int		channel ;		// ���ϥ����ͥ��ֹ�
	int		real_chno ;		// �ºݤΥơ��֥��ֹ�
	int		slotno ;		// ����å��ֹ�
}ISDB_S_CH_TABLE ;

/***************************************************************************/
/* ISDB-S�������                                                         */
/***************************************************************************/
typedef	struct	_ISDB_S_TS_ID{
	__u16	ts_id ;			// TS-ID
	__u16	dmy ;			// PAD
	__u8	low_mode ;		// �㳬�� �⡼��
	__u8	low_slot ;		// �㳬�� ����åȿ�
	__u8	high_mode ;		// �ⳬ�� �⡼��
	__u8	high_slot ;		// �ⳬ�� ����åȿ�
}ISDB_S_TS_ID;
typedef	struct	_ISDB_S_TMCC{
	ISDB_S_TS_ID	ts_id[MAX_BS_TS_ID];	// ����TS�ֹ�n���Ф���TS ID����
#if 0
	__u32	indicator;				// �ѹ��ؼ� (5�ӥå�)
	__u32	emergency;				// ��ư���濮�� (1�ӥå�)
	__u32	uplink;					// ���åץ��������� (4�ӥå�)
	__u32	ext;					// ��ĥ�ե饰 (1�ӥå�)
	__u32	extdata[2];				// ��ĥ�ΰ� (61�ӥå�)
#endif
	__u32	agc ;					// AGC
	__u32	clockmargin ;			// ����å����ȿ���
	__u32	carriermargin ;			// ����ꥢ���ȿ���
}ISDB_S_TMCC;

// ���ؾ���
typedef	struct	_ISDB_T_INFO{
	__u32	mode;				// ����ꥢ��Ĵ���� (3�ӥå�)
	__u32	rate;				// ��������沽Ψ (3�ӥå�)
	__u32	interleave;			// ���󥿡��꡼��Ĺ (3�ӥå�)
	__u32	segment; 			// �������ȿ� (4�ӥå�)
}ISDB_T_INFO;

typedef	struct	_ISDB_T_TMCC {
#if 0
	__u32	sysid;		// �����ƥ༱�� (2�ӥå�)
	__u32	indicator;	// �����ѥ�᡼���ڤ��ؤ���ɸ (4�ӥå�)
	__u32	emergency;	// �۵޷��������ѵ�ư�ե饰 (1�ӥå�)
#endif
	ISDB_T_INFO	info[MAX_ISDB_T_INFO];
#if 0
						// �����Ⱦ���
	__u32	partial;	// ��ʬ�����ե饰 (1�ӥå�)
	__u32	Phase;		// Ϣ���������������� (3�ӥå�)
	__u32	Reserved;	// �ꥶ���� (12�ӥå�)
#endif
	__u32	cn[2] ;					// CN
	__u32	agc ;					// AGC
	__u32	clockmargin ;			// ����å����ȿ���
	__u32	carriermargin ;			// ����ꥢ���ȿ���
}ISDB_T_TMCC;
/***************************************************************************/
/* ���塼�ʾ������                                                        */
/***************************************************************************/
extern	void	settuner_reset(void __iomem *, int, __u32, __u32);
extern	int		tuner_init(void __iomem *, int, struct mutex *, int);
extern	void	set_sleepmode(void __iomem *, struct mutex *, int, int, int);

extern	int		bs_tune(void __iomem *, struct mutex *, int, int, ISDB_S_TMCC *);
extern  int     ts_lock(void __iomem *, struct mutex *, int, __u16);

extern	int		isdb_t_tune(void __iomem *, struct mutex *, int, int, ISDB_T_TMCC *);
extern	int		isdb_t_frequency(void __iomem *, struct mutex *, int, int, int);
extern	int		isdb_s_read_signal_strength(void __iomem *, struct mutex *, int);
extern	int		isdb_t_read_signal_strength(void __iomem *, struct mutex *, int);

#endif
