uint8_t m8013poll()
{
    static uint32_t eee = 0;
    static uint8_t _b,_s;
    
    if (millis() - eee >= 500UL) 
    {
      if (millis() - eee >= 1000UL) { _s = 0; eee=millis(); }
      else { _s = 1; }
      
    }
    _8013state = _s; 
    return _s;
}
uint8_t m8013(uint8_t a) { 
  static uint8_t _b=0; 
  if (!a && _b) { _b=0; return 0; } 
  else if (a && !_b) { _b=1; return 1; } 
  else { return 0; } 
}

