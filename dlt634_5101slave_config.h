/*
** ------------------------------- Copyright (c) -------------------------------                                     
**
**                           http://www.sojoline.com
**
** note:    Copyright SOJO. ALL RIGHTS RESERVED.
**          This software is provided under license and contains proprietary and
**          confidential material which is the property of Company Name tech. 
**    
** -------------------------------- File Info ----------------------------------
** File name:               dlt634_5101slave_config.h
** Descriptions:            The application layer of DL/T634.5101_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.j
** Created date:            2015.10.25
** System:                  Protocol Software System
** Version:                 V3.01
** Descriptions:            The original version
**
** -----------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
** ---------------------------------------------------------------------------*/
#ifndef	_DLT634_5101SLAVE_CONFIG_H_
#define _DLT634_5101SLAVE_CONFIG_H_


/* PUBLIC VARIABLE -----------------------------------------------------------*/
enum
{
    DLT634_5101SLAVE_DISK0 = 0,
    _DLT634_5101SLAVE_VOLUMES
};
/* Number of volumes (logical drives) to be used.*/
#define _DLT634_5101SLAVE_LPDUSIZE  256
#define _DLT634_5101SLAVE_STOREDATA1NUM	10
#define _DLT634_5101SLAVE_STOREDATA2NUM	20

#define  _DLT634_5101SLAVE_NUMOF_MAXRETRY                0x03 // ƒ¨»œDL/T634.5101_2002πÊ‘º¡¥¬∑Ω®¡¢◊Ó∂‡¡¨Ω”¥Œ ˝

//LINK_FLAG
#define  _DLT634_5101SLAVE_REQSTATUS                  0x00000001
#define  _DLT634_5101SLAVE_RECONFIRM                  0x00000002
#define  _DLT634_5101SLAVE_ASKSTATUS                  0x00000004
#define  _DLT634_5101SLAVE_ASKRELINK                  0x00000008

#define  _DLT634_5101SLAVE_SENDABLE                  	0x00100000// ∆Ω∫‚
#define  _DLT634_5101SLAVE_REDATA1                  	0x00400000// ∑«∆Ω∫‚
#define  _DLT634_5101SLAVE_REDATA2                  	0x00800000// ∑«∆Ω∫‚

#define  _DLT634_5101SLAVE_FIRST_ALL_CALLSTART       	0x10000000
#define  _DLT634_5101SLAVE_FIRST_ALL_CALLEND        	0x20000000
#define  _DLT634_5101SLAVE_FIRST_RlaConCode         	0x40000000
#define  _DLT634_5101SLAVE_INITEND                  	0x80000000

//1º∂ ˝æ›◊¥Ã
#define  _DLT634_5101SLAVE_HAVESTDATA1                0x00000001
#define  _DLT634_5101SLAVE_HAVEINITEND                0x00000002
#define  _DLT634_5101SLAVE_HAVERESET                  0x00000004
#define  _DLT634_5101SLAVE_CALLALLDATA                0x00000010
#define  _DLT634_5101SLAVE_HAVESOE                    0x00000020

/*************************************************************************************************************************************/
//DL/T634.5101_2002πÊ‘º

/* ¡¥¬∑≤„÷°–ﬁ Œ¥ ***************************************************************/
#define  _DLT634_5101SLAVE_STARTCODE10	                     0x10	// ∆ º¬Î
#define  _DLT634_5101SLAVE_STARTCODE68	                     0x68	// ∆ º¬Î
#define  _DLT634_5101SLAVE_ENDCODE                           0x16	// ÷’÷π¬Î

/* ¡¥¬∑≤„øÿ÷∆”Ú∂®“Â************************************************************/
//«∞4Œª
#define  _DLT634_5101SLAVE_FUNCODE                       0x0F // π¶ƒ‹¬Î
#define  _DLT634_5101SLAVE_FCV                           0x10 // ÷°º∆ ˝”––ßŒª 
#define  _DLT634_5101SLAVE_DFC                           0x10 //  ˝æ›¡˜øÿ÷∆
#define  _DLT634_5101SLAVE_FCB                           0x20 // ÷°º∆ ˝Œª
#define  _DLT634_5101SLAVE_ACD                           0x20 // “™«Û∑√Œ Œª 
#define  _DLT634_5101SLAVE_PRM                           0x40 // ∆Ù∂Ø±®ŒƒŒª
#define  _DLT634_5101SLAVE_DIR                           0x80 // ¥´ ‰∑ΩœÚŒª

//¡¥¬∑≤„÷˜’æœÚ◊”’æ¥´ ‰π¶ƒ‹¬Î∂®“Â
#define   _DLT634_5101SLAVE_M_FUN0             	0           // ∏¥Œª‘∂∑Ω¡¥¬∑
#define   _DLT634_5101SLAVE_M_FUN2              2           // ≤‚ ‘¡¥¬∑π¶ƒ‹ 
#define   _DLT634_5101SLAVE_M_FUN3              3	          // ∑¢ÀÕ»∑»œ√¸¡Ó
#define   _DLT634_5101SLAVE_M_FUN4             	4	          // ∑¢ÀÕ≤ª»∑»œ√¸¡Ó
#define   _DLT634_5101SLAVE_M_FUN8              8	          // «Î«ÛœÏ”¶»∑∂®∑√Œ ◊¥Ã¨
#define   _DLT634_5101SLAVE_M_FUN9             	9	          // ’ŸªΩ¡¥¬∑◊¥Ã¨
#define   _DLT634_5101SLAVE_M_FUN10             10	        // ’ŸªΩ1º∂”√ªß ˝æ› 
#define   _DLT634_5101SLAVE_M_FUN11             11          // ’ŸªΩ2º∂”√ªß ˝æ›

//*¡¥¬∑≤„◊”’æœÚ÷˜’æ¥´ ‰π¶ƒ‹¬Î∂®“Â 
#define   _DLT634_5101SLAVE_S_FUN0              0            // »∑»œ
#define   _DLT634_5101SLAVE_S_FUN1              1            // »∑»œ¡¥¬∑√¶Œ¥Ω” ’±®Œƒ
#define   _DLT634_5101SLAVE_S_FUN8              8            // “‘ ˝æ›œÏ”¶«Î«Û÷°
#define   _DLT634_5101SLAVE_S_FUN9              9            // ŒﬁÀ˘’ŸªΩµƒ ˝æ›
#define   _DLT634_5101SLAVE_S_FUN11             11           // œÏ”¶¡¥¬∑◊¥Ã¨ªÚªÿ¥«Î«Û÷°
 
/* TI¿‡–Õ±Í ∂ ********************************************************************************/ 
//º‡ ”∑ΩœÚπ˝≥Ã–≈œ¢
#define   _DLT634_5101SLAVE_M_SP_NA_1              1            // µ•µ„–≈œ¢
#define   _DLT634_5101SLAVE_M_DP_NA_1              3            // À´µ„–≈œ¢
#define   _DLT634_5101SLAVE_M_ME_NA_1              9            // ≤‚¡ø÷µ£¨πÈ“ªªØ÷µ
#define   _DLT634_5101SLAVE_M_ME_NB_1              11           // ≤‚¡ø÷µ£¨±Í∂»ªØ÷µ
#define   _DLT634_5101SLAVE_M_ME_NC_1              13           // ≤‚¡ø÷µ£¨∂Ã∏°µ„ ˝
#define   _DLT634_5101SLAVE_M_SP_TB_1              30           // ¥¯ ±±Íµƒµ•µ„–≈œ¢
#define   _DLT634_5101SLAVE_M_DP_TB_1              31           // ¥¯ ±±ÍµƒÀ´µ„–≈œ¢
#define   _DLT634_5101SLAVE_M_FT_NA_1              42           // π ’œ ¬º˛–≈œ¢
#define   _DLT634_5101SLAVE_M_IT_NB_1              206          // ¿€º∆¡ø£¨∂Ã∏°µ„ ˝
#define   _DLT634_5101SLAVE_M_IT_TC_1              207          // ¥¯ ±±Í¿€º∆¡ø£¨∂Ã∏°µ„ ˝

//øÿ÷∆∑ΩœÚπ˝≥Ã–≈œ¢
#define   _DLT634_5101SLAVE_C_SC_NA_1              45            // µ•µ„√¸¡Ó
#define   _DLT634_5101SLAVE_C_SC_NB_1              46            // À´µ„√¸¡Ó

//º‡ ”∑ΩœÚµƒœµÕ≥√¸¡Ó
#define   _DLT634_5101SLAVE_M_EI_NA_1              70            // ≥ı ºªØΩ· ¯

//øÿ÷∆∑ΩœÚµƒœµÕ≥√¸¡Ó
#define   _DLT634_5101SLAVE_C_IC_NA_1              100            // ’æ◊‹’ŸªΩ√¸¡Ó
#define   _DLT634_5101SLAVE_C_CI_NA_1              101            // µÁƒ‹¡ø’ŸªΩ√¸¡Ó
#define   _DLT634_5101SLAVE_C_CS_NA_1              103            //  ±º‰Õ¨≤Ω√¸¡Ó
#define   _DLT634_5101SLAVE_C_TS_NA_1              104            // ≤‚ ‘√¸¡Ó
#define   _DLT634_5101SLAVE_C_RP_NA_1              105            // ∏¥ŒªΩ¯≥Ã√¸¡Ó
#define   _DLT634_5101SLAVE_C_SR_NA_1              200            // «–ªª∂®÷µ«¯
#define   _DLT634_5101SLAVE_C_RR_NA_1              201            // ∂¡∂®÷µ«¯∫≈
#define   _DLT634_5101SLAVE_C_RS_NA_1              202            // ∂¡≤Œ ˝∫Õ∂®÷µ
#define   _DLT634_5101SLAVE_C_WS_NA_1              203            // –¥≤Œ ˝∫Õ∂®÷µ
#define   _DLT634_5101SLAVE_F_FR_NA_1              210            // Œƒº˛¥´ ‰
#define   _DLT634_5101SLAVE_F_SR_NA_1              211            // »Ìº˛…˝º∂

/* COT¥´ÀÕ‘≠“Ú ********************************************************************************/ 
#define   _DLT634_5101SLAVE_COT_CYC              1            // ÷‹∆⁄—≠ª∑
#define   _DLT634_5101SLAVE_COT_BACK             2            // ±≥æ∞…®√Ë
#define   _DLT634_5101SLAVE_COT_SPONT            3            // Õª∑¢
#define   _DLT634_5101SLAVE_COT_INIT             4            // ≥ı ºªØ
#define   _DLT634_5101SLAVE_COT_REQ              5            // «Î«ÛªÚ±ª«Î«Û
#define   _DLT634_5101SLAVE_COT_ACT              6            // º§ªÓ
#define   _DLT634_5101SLAVE_COT_ACTCON           7            // º§ªÓ»∑»œ
#define   _DLT634_5101SLAVE_COT_DEACT            8            // Õ£÷πº§ªÓ
#define   _DLT634_5101SLAVE_COT_DEACTCON         9            // Õ£÷πº§ªÓ»∑»œ
#define   _DLT634_5101SLAVE_COT_ACCTTERM         10            // º§ªÓ÷’÷π
#define   _DLT634_5101SLAVE_COT_FILE             13            // Œƒº˛¥´ ‰
#define   _DLT634_5101SLAVE_COT_INTROGEN         20            // œÏ”¶’æ’ŸªΩ
#define   _DLT634_5101SLAVE_COT_REQCOGEN         37            // œÏ”¶µÁƒ‹’ŸªΩ

/* ∑¢ÀÕ”≈œ»º∂ ********************************************************************************/
//1º∂ ˝æ›
#define   _DLT634_5101SLAVE_M_EI_NA_P              1            // ≥ı ºªØΩ· ¯
#define   _DLT634_5101SLAVE_C_IC_NA_PF             2            // ’æ◊‹’ŸªΩ√¸¡Ó
#define   _DLT634_5101SLAVE_C_SC_NA_P              3            // µ•µ„√¸¡Ó,∂®÷µ√¸¡Ó
#define   _DLT634_5101SLAVE_M_SP_TB_P              4           // ¥¯ ±±Íµƒµ•µ„–≈œ¢
#define   _DLT634_5101SLAVE_C_IC_NA_P              5            // ’æ◊‹’ŸªΩ√¸¡Ó£¨∂®÷µ’ŸªΩ

//2º∂ ˝æ›
#define   _DLT634_5101SLAVE_M_FT_NA_P              0x81           // π ’œ ¬º˛–≈œ¢
#define   _DLT634_5101SLAVE_C_CS_NA_P              0x82            //  ±º‰Õ¨≤Ω√¸¡Ó
#define   _DLT634_5101SLAVE_C_TS_NA_P              0x83            // ≤‚ ‘√¸¡Ó
#define   _DLT634_5101SLAVE_M_ME_NC_P              0x84           // ≤‚¡ø÷µ£¨∂Ã∏°µ„ ˝
#define   _DLT634_5101SLAVE_C_RP_NA_P              0x85            // ∏¥ŒªΩ¯≥Ã√¸¡Ó
#define   _DLT634_5101SLAVE_F_FR_NA_P              0x86            // Œƒº˛’ŸªΩ
#define   _DLT634_5101SLAVE_F_FW_NA_P              0x87            // Œƒº˛¥´ ‰
#define   _DLT634_5101SLAVE_C_CI_NA_P              0x88            // µÁƒ‹¡ø’ŸªΩ√¸¡Ó

#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/
