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
    static uint32_t eee=0; static uint8_t _s, _a, _b; out;
    if (!_a && _b) { _b=0; out=0; }
    else if (_a && !_b) { _b=1; out=1; }
    else { out=0; }
    
    if (millis() - eee >= 500UL) { if (millis() - eee >= 1000UL) { _s = 0; eee=millis(); }  else { _s = 1; }      }
    _a=_s;
    return out;
}
uint8_t m8013(uint16_t _SWITCH, uint16_t _MAX) {
    static uint32_t eee=0; static uint8_t _s, _a, _b; out;
    if (!_a && _b) { _b=0; out=0; }
    else if (_a && !_b) { _b=1; out=1; }
    else { out=0; }
    
    if (millis() - eee >= _SWITCH) { if (millis() - eee >= _MAX) { _s = 0; eee=millis(); }  else { _s = 1; }      }
    _a=_s;
    return out;
}
