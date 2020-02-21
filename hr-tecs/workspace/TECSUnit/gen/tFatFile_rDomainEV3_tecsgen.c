/*
 * ���Υե������ tecsgen �ˤ�꼫ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥϡ��տޤ���Ƥ��ޤ���
 */
#include "tFatFile_tecsgen.h"
#include "tFatFile_factory.h"

/* �������ǥ�������ץ��� #_EDT_# */
/* eFatFile */
struct tag_tFatFile_eFatFile_DES {
    const struct tag_sFatFile_VMT *vmt;
    tFatFile_IDX  idx;
};

/* ������������ȥ�ؿ� #_EPSF_# */
/* eFatFile */
FRESULT        tFatFile_eFatFile_fopen_skel( const struct tag_sFatFile_VDES *epd, const TCHAR* path, const TCHAR* mode)
{
    struct tag_tFatFile_eFatFile_DES *lepd
        = (struct tag_tFatFile_eFatFile_DES *)epd;
    return tFatFile_eFatFile_fopen( lepd->idx, path, mode );
}
FRESULT        tFatFile_eFatFile_fclose_skel( const struct tag_sFatFile_VDES *epd)
{
    struct tag_tFatFile_eFatFile_DES *lepd
        = (struct tag_tFatFile_eFatFile_DES *)epd;
    return tFatFile_eFatFile_fclose( lepd->idx );
}
FRESULT        tFatFile_eFatFile_fread_skel( const struct tag_sFatFile_VDES *epd, TCHAR* buffer, UINT btr)
{
    struct tag_tFatFile_eFatFile_DES *lepd
        = (struct tag_tFatFile_eFatFile_DES *)epd;
    return tFatFile_eFatFile_fread( lepd->idx, buffer, btr );
}
FRESULT        tFatFile_eFatFile_fwrite_skel( const struct tag_sFatFile_VDES *epd, const TCHAR* buffer, UINT btw, UINT* bw)
{
    struct tag_tFatFile_eFatFile_DES *lepd
        = (struct tag_tFatFile_eFatFile_DES *)epd;
    return tFatFile_eFatFile_fwrite( lepd->idx, buffer, btw, bw );
}
TCHAR*         tFatFile_eFatFile_fgets_skel( const struct tag_sFatFile_VDES *epd, TCHAR* buff, uint_t btr)
{
    struct tag_tFatFile_eFatFile_DES *lepd
        = (struct tag_tFatFile_eFatFile_DES *)epd;
    return tFatFile_eFatFile_fgets( lepd->idx, buff, btr );
}
FRESULT        tFatFile_eFatFile_unlink_skel( const struct tag_sFatFile_VDES *epd, const TCHAR* path)
{
    struct tag_tFatFile_eFatFile_DES *lepd
        = (struct tag_tFatFile_eFatFile_DES *)epd;
    return tFatFile_eFatFile_unlink( lepd->idx, path );
}
FRESULT        tFatFile_eFatFile_fmount_skel( const struct tag_sFatFile_VDES *epd, const TCHAR* path, BYTE opt)
{
    struct tag_tFatFile_eFatFile_DES *lepd
        = (struct tag_tFatFile_eFatFile_DES *)epd;
    return tFatFile_eFatFile_fmount( lepd->idx, path, opt );
}

/* ������������ȥ�ؿ��ơ��֥� #_EPSFT_# */
/* eFatFile */
const struct tag_sFatFile_VMT tFatFile_eFatFile_MT_ = {
    tFatFile_eFatFile_fopen_skel,
    tFatFile_eFatFile_fclose_skel,
    tFatFile_eFatFile_fread_skel,
    tFatFile_eFatFile_fwrite_skel,
    tFatFile_eFatFile_fgets_skel,
    tFatFile_eFatFile_unlink_skel,
    tFatFile_eFatFile_fmount_skel,
};

/* �ƤӸ��λ��Ȥ���������ǥ�������ץ�(�ºݤη�����㤷�����) #_CPEPD_# */

/* �ƤӸ����� #_CPA_# */

/* °�����ѿ������� #_AVAI_# */
/* ���� CB #_CB_# */
struct tag_tFatFile_CB tFatFile_CB_tab[1];
extern const struct tag_sFatFile_VMT tFatFile_eFatFile_MT_;
/* �������ǥ�������ץ� #_EPD_# */
extern const struct tag_tFatFile_eFatFile_DES rDomainEV3_FatFile_eFatFile_des;
const struct tag_tFatFile_eFatFile_DES rDomainEV3_FatFile_eFatFile_des = {
    &tFatFile_eFatFile_MT_,
    &tFatFile_CB_tab[0],      /* CB 3 */
};
/* CB ����������� #_CIC_# */
void
tFatFile_CB_initialize()
{
    tFatFile_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
