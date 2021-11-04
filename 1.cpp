if( !Lverf_Money(hDlg,IDD_INS_DEDUCTMET_PER1,&tmpMoney,1) )
							{
								Lfmt_FormatMoney(cBuff,gmPatStand);
								SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_PER1,(LPSTR)cBuff);
								bProcessingKillFocus = FALSE;
								break;
							}
							moneyDiff = tmpMoney - gmPatStand;
							if( moneyDiff != 0 )
							{
								gmPatStand = tmpMoney;
								gmLifeStand = gmLifeStand + moneyDiff;
								gmFamStand = gmFamStand + moneyDiff;
								gmLifeStand = max(0,gmLifeStand);
								gmFamStand = max(0,gmFamStand);
								Lfmt_FormatMoney(cBuff,gmLifeStand);
								SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_PER_LT1,(LPSTR)cBuff);
								Lfmt_FormatMoney(cBuff,gmFamStand);
								SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_FAM1,(LPSTR)cBuff);
								if( gmPatStand < 0 )
								{
									gmPatStand = 0;
									Lfmt_FormatMoney(cBuff,gmPatStand);
									SetDlgItemText(hDlg,IDD_INS_DEDUCTMET_PER1,(LPSTR)cBuff);
								}
							}