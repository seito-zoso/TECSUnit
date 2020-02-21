/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#ifndef tTarget_TECSGEN_H
#define tTarget_TECSGEN_H

/*
 * celltype          :  tTarget
 * global name       :  tTarget
 * multi-domain      :  no
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  yes
 * has_INIB          :  no
 * rom               :  yes
 * CB initializer    :  yes
 */

/* �����Х�إå� #_IGH_# */
#include "global_tecsgen.h"

/* �����˥���إå� #_ISH_# */
#include "sTarget_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ���� CB ����� #_CCTPA_# */
typedef struct tag_tTarget_CB {
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    int8_t         data1;
    int8_t         data2;
}  tTarget_CB;
/* ���󥰥�ȥ󥻥� CB �ץ�ȥ�������� #_MCPB_# */
extern tTarget_CB  tTarget_CB_tab[];

/* ���륿���פ�IDX�� #_CTIX_# */
typedef struct tag_tTarget_CB *tTarget_IDX;

/* �������ؿ��ץ�ȥ�������� #_EPP_# */
/* sTarget */
int          tTarget_eTarget_main(tTarget_IDX idx, int8_t a, int8_t b);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tTarget_ID_BASE             (1)  /* ID �Υ١���  #_NIDB_# */
#define tTarget_N_CELL              (1)  /* ����θĿ�  #_NCEL_# */

/* IDX�������������å��ޥ��� #_CVI_# */
#define tTarget_VALID_IDX(IDX) (1)


/* ����CB������ޥ��� #_GCB_# */
#define tTarget_GET_CELLCB(idx) (idx)



/* var ���������ޥ��� #_VAM_# */
#define tTarget_VAR_data1(p_that)	((p_that)->data1)
#define tTarget_VAR_data2(p_that)	((p_that)->data2)

#define tTarget_GET_data1(p_that)	((p_that)->data1)
#define tTarget_SET_data1(p_that,val)	((p_that)->data1=(val))
#define tTarget_GET_data2(p_that)	((p_that)->data2)
#define tTarget_SET_data2(p_that,val)	((p_that)->data2=(val))

#ifndef TECSFLOW
#else  /* TECSFLOW */
#endif /* TECSFLOW */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ������������ȥ�ؿ��ץ�ȥ����������VMT���׺�Ŭ���ˤ�껲�Ȥ����Ρ� #_EPSP_# */
/* eTarget */
int            tTarget_eTarget_main_skel( const struct tag_sTarget_VDES *epd, int8_t a, int8_t b);

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDX�������������å��ޥ����û�̷��� #_CVIA_# */
#define VALID_IDX(IDX)  tTarget_VALID_IDX(IDX)


/* ����CB������ޥ���(û�̷�) #_GCBA_# */
#define GET_CELLCB(idx)  tTarget_GET_CELLCB(idx)

/* CELLCB ��(û�̷�) #_CCT_# */
#define CELLCB	tTarget_CB

/* ���륿���פ�IDX��(û�̷�) #_CTIXA_# */
#define CELLIDX	tTarget_IDX



/* var ���������ޥ���(û�̷�) #_VAMA_# */
#define VAR_data1            tTarget_VAR_data1( p_cellcb )
#define VAR_data2            tTarget_VAR_data2( p_cellcb )




/* �������ؿ��ޥ����û�̷��� #_EPM_# */
#define eTarget_main     tTarget_eTarget_main

/* ���ƥ졼�������� (FOREACH_CELL)������ #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tTarget_N_CELL; (i)++ ){ \
       (p_cb) = &tTarget_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB ������ޥ��� #_CIM_# */
#define INITIALIZE_CB(p_that)\
	(p_that)->data1 = 0;\
	(p_that)->data2 = 0;
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tTarget_TECSGENH */
