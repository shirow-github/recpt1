#ifndef		__PT1_I2C_H__
#define		__PT1_I2C_H__
#include <linux/mutex.h>
/***************************************************************************/
/* I2C�ǡ����������                                                       */
/***************************************************************************/
#define		MAX_CHANNEL			4		// ����ͥ��

#define		FALSE		0
#define		TRUE		1

/***************************************************************************/
/* I2C�ǡ����������                                                       */
/***************************************************************************/
#define		I2C_ADDRESS		10		// I2C���ɥ쥹(10�ӥå�)

#define		I2C_DATA_EN		10
#define		I2C_CLOCK		11
#define		I2C_WRIET_MODE	12		// I2C�񤭹��ߡ��ɤ߹���
#define		I2C_BUSY		13
#define		I2C_DATA		18		// I2C�ǡ���(18�ӥå�)
/***************************************************************************/
/* I2C���                                                                 */
/***************************************************************************/
#define		WRITE_EN		1		// �񤭹���
#define		READ_EN			0		// �ɤ߹���
#define		DATA_EN			1		// �ǡ�������
#define		DATA_DIS		0		// �ǡ����ʤ�
#define		CLOCK_EN		1		// CLOCK����
#define		CLOCK_DIS		0		// CLOCK�ʤ�
#define		BUSY_EN			1		// BUSY����
#define		BUSY_DIS		0		// BUSY�ʤ�

/***************************************************************************/
/*                                                                         */
/***************************************************************************/
#define		PCI_LOCKED			1
#define		RAM_LOCKED			2
#define		RAM_SHIFT			4
/***************************************************************************/
/* �ӥå�                                                                  */
/***************************************************************************/
#define		WRITE_PCI_RESET		(1 << 16)
#define		WRITE_PCI_RESET_	(1 << 24)
#define		WRITE_RAM_RESET		(1 << 17)
#define		WRITE_RAM_RESET_	(1 << 25)
#define		WRITE_RAM_ENABLE	(1 << 1)

#define		WRITE_PULSE			(1 << 3)
#define		I2C_READ_SYNC		(1 << 29)
#define		READ_DATA			(1 << 30)
#define		READ_UNLOCK			(1 << 31)

#define		XC3S_PCI_CLOCK		(512 / 4)
#define		XC3S_PCI_CLOCK_PT2	(166)
/***************************************************************************/
/* I2C���ɥ쥹���                                                         */
/***************************************************************************/
#define		T0_ISDB_S			0X1B		// ���塼��0 ISDB-S
#define		T1_ISDB_S			0X19		// ���塼��1 ISDB-S

#define		T0_ISDB_T			0X1A		// ���塼��0 ISDB-T
#define		T1_ISDB_T			0X18		// ���塼��1 ISDB-T

/***************************************************************************/
/* I2C�񤭹��ߥǡ������                                                   */
/***************************************************************************/
typedef	struct	_WBLOCK{
	__u8	addr ;			// I2C�ǥХ������ɥ쥹
	__u32	count ;			// ž���Ŀ�
	__u8	value[16];		// �񤭹�����
}WBLOCK;

/***************************************************************************/
/* �ؿ����                                                                */
/***************************************************************************/
//extern	__u32	makei2c(void __iomem *, __u32, __u32, __u32, __u32, __u32, __u32);
extern	int		xc3s_init(void __iomem *, int);
extern	void	SetStream(void __iomem *, __u32, __u32);
extern	void	blockwrite(void __iomem *, WBLOCK *);
extern	void	i2c_write(void __iomem *, struct mutex *, WBLOCK *);
extern	__u32	i2c_read(void __iomem *, struct mutex *, WBLOCK *, int);

#endif
