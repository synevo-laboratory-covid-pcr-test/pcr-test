if( !Lverf_Money(hDlg,IDD_INS_DEDUCTMET_PER2,&tmpMoney,1) )
							{
								Lfmt_FormatMoney(cBuff,gmPatPrev);
								SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_PER2,(LPSTR)cBuff);
								bProcessingKillFocus = FALSE;
								break;
							}
							moneyDiff = tmpMoney - gmPatPrev;
							if( moneyDiff != 0 )
							{
								gmPatPrev = tmpMoney;
								gmLifePrev = gmLifePrev + moneyDiff;
								gmFamPrev = gmFamPrev + moneyDiff;
								gmLifePrev = max(0,gmLifePrev);
								gmFamPrev = max(0,gmFamPrev);
								Lfmt_FormatMoney(cBuff,gmLifePrev);
								SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_PER_LT2,(LPSTR)cBuff);
								Lfmt_FormatMoney(cBuff,gmFamPrev);
								SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_FAM2,(LPSTR)cBuff);
								if( gmPatPrev < 0 )
								{
									gmPatPrev = 0;
									Lfmt_FormatMoney(cBuff,gmPatPrev);
									SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_PER2,(LPSTR)cBuff);
								}
							}