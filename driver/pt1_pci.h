#ifndef		__PT1_PCI_H__
#define		__PT1_PCI_H__
/***************************************************************************/
/* PCI���ɥ쥹���                                                         */
/***************************************************************************/
#define		FIFO_GO			0x04			// FIFO�¹�
#define		FIFO_DONE		0x80			// FIFO �¹���ӥå�
/***************************************************************************/
/* PCI���ɥ쥹���                                                         */
/***************************************************************************/
#define		FIFO_GO_ADDR		0x00			// FIFO �¹ԥ��ɥ쥹
#define		FIFO_RESULT_ADDR	0x00			// FIFO ��̾���
#define		CFG_REGS_ADDR		0x04
#define		I2C_RESULT_ADDR		0x08			// I2C�������
#define		FIFO_ADDR			0x10			// FIFO�˽񤯥��ɥ쥹
#define		DMA_ADDR			0x14			// DMA����˽񤯥��ɥ쥹
#define		TS_TEST_ENABLE_ADDR	0x08			//

/***************************************************************************/
/* DMA���顼���                                                           */
/***************************************************************************/
#define		MICROPACKET_ERROR		1			// Micro Packet���顼
#define		BIT_RAM_OVERFLOW		(1 << 3)	//
#define		BIT_INITIATOR_ERROR		(1 << 4)	//
#define		BIT_INITIATOR_WARNING	(1 << 5)	//

/***************************************************************************/
/***************************************************************************/
extern int debug;
#define PT1_PRINTK(verbose, level, fmt, args...)      {if(verbose <= debug)printk(level "PT1: " fmt, ##args);}
#endif
