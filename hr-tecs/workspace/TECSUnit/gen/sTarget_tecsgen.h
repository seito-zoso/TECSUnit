/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#ifndef sTarget_TECSGEN_H
#define sTarget_TECSGEN_H

/*
 * signature   :  sTarget
 * global name :  sTarget
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* �����˥���ǥ�������ץ� #_SD_# */
struct tag_sTarget_VDES {
    struct tag_sTarget_VMT *VMT;
};

/* �����˥���ؿ��ơ��֥� #_SFT_# */
struct tag_sTarget_VMT {
    int            (*main__T)( const struct tag_sTarget_VDES *edp, int8_t a, int8_t b );
};

/* �����˥���ǥ�������ץ�(ưŪ�����) #_SDES_# */
#ifndef Descriptor_of_sTarget_Defined
#define  Descriptor_of_sTarget_Defined
typedef struct { struct tag_sTarget_VDES *vdes; } Descriptor( sTarget );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_STARGET_MAIN                    (1)

#endif /* sTarget_TECSGEN_H */
