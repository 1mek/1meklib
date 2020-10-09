uint8_t m8013poll()
{
    static uint32_t eee = 0;
    static uint8_t _s;
    
    if (millis() - eee >= 500UL) 
    {
      if (millis() - eee >= 1000UL) { _s = 0; eee=millis(); }
      else { _s = 1; }
      
    }
    return _s;
}
uint8_t m8013(uint8_t a) { 
  static uint8_t _b=0; 
  if (!a && _b) { _b=0; return 0; } 
  else if (a && !_b) { _b=1; return 1; } 
  else { return 0; } 
}


// In same.

uint8_t m8013() {
    static uint32_t eee=0; static uint8_t _s, _a, _b, out;
    if (!_a && _b) { _b=0; out=0; }
    else if (_a && !_b) { _b=1; out=1; }
    else { out=0; }
    
    if (millis() - eee >= 500UL) { if (millis() - eee >= 1000UL) { _s = 0; eee=millis(); }  else { _s = 1; }      }
    _a=_s;
    return out;
}
uint8_t m8013(uint16_t _SWITCH, uint16_t _MAX) {
    static uint32_t eee=0; static uint8_t _s, _a, _b, out;
    if (!_a && _b) { _b=0; out=0; }
    else if (_a && !_b) { _b=1; out=1; }
    else { out=0; }
    
    if (millis() - eee >= _SWITCH) { if (millis() - eee >= _MAX) { _s = 0; eee=millis(); }  else { _s = 1; }      }
    _a=_s;
    return out;
}




//


void mCtrlBox()
{
     if (M5.BtnC.wasPressed()) _mCtrlRestart = 1;
     static uint8_t Act, MKRCW, MKRFW, MKRCA, MKRFA, LarmAct, EnLarm, EnRun, wP;
     if (Act) { EnLarm = 1; EnRun = 1; } else { EnRun=0; }
     if (M5.BtnA.wasPressed() || _mCtrlRestart) { EnLarm=0; Act=Act?0:1; mekt.mPrint("A=" + String(Act)); }
     if (Act && _mCtrlRestart) _mCtrlRestart=0;
     if (Act && m801x(800,1000)) wP++;
     
     MKRCA = mtimeaT(MKRCW, EnLarm); MKRFA = mtimeaF(MKRFW, EnLarm);
     mDORLY(EnRun);
     if (EnLarm) { MKRCW = mb_larmNtu(); MKRFW = mFRQ_larm(); } else { MKRCW=0;MKRFW=0; }
     
     if (LarmAct != 0) {   Act=0;  }

     alarmX="";
     alarmX += " ACT" + String(Act) + " EnL" + String(EnLarm) + " EnR" + String(EnRun) + " wP" + String(wP);
     alarmX += String(_8013state) + String(_8013changed);
     alarmX += " CW" + String(MKRCW) + " FW" + String(MKRFW);
     alarmX += " CA" + String(MKRCA) + " FA" + String(MKRFA) + "\r\n";
     
     
     if (wP>=5) LarmAct = MKRCA + MKRFA; 

}
