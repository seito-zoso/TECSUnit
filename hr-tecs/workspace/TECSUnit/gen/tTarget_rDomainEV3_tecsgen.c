/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#include "tTarget_tecsgen.h"
#include "tTarget_factory.h"

/* �������ǥ�������ץ��� #_EDT_# */
/* eTarget */
struct tag_tTarget_eTarget_DES {
    const struct tag_sTarget_VMT *vmt;
    tTarget_IDX  idx;
};

/* ������������ȥ�ؿ� #_EPSF_# */
/* eTarget */
int            tTarget_eTarget_main_skel( const struct tag_sTarget_VDES *epd, int8_t a, int8_t b)
{
    struct tag_tTarget_eTarget_DES *lepd
        = (struct tag_tTarget_eTarget_DES *)epd;
    return tTarget_eTarget_main( lepd->idx, a, b );
}

/* ������������ȥ�ؿ��ơ��֥� #_EPSFT_# */
/* eTarget */
const struct tag_sTarget_VMT tTarget_eTarget_MT_ = {
    tTarget_eTarget_main_skel,
};

/* �ƤӸ��λ��Ȥ���������ǥ�������ץ�(�ºݤη�����㤷�����) #_CPEPD_# */

/* �ƤӸ����� #_CPA_# */

/* °�����ѿ������� #_AVAI_# */
/* ���� CB #_CB_# */
struct tag_tTarget_CB tTarget_CB_tab[1];
extern const struct tag_sTarget_VMT tTarget_eTarget_MT_;
/* �������ǥ�������ץ� #_EPD_# */
extern const struct tag_tTarget_eTarget_DES rDomainEV3_Target_eTarget_des;
const struct tag_tTarget_eTarget_DES rDomainEV3_Target_eTarget_des = {
    &tTarget_eTarget_MT_,
    &tTarget_CB_tab[0],      /* CB 3 */
};
/* CB ����������� #_CIC_# */
void
tTarget_CB_initialize()
{
    tTarget_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
