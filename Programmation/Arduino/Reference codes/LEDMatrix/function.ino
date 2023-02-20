
void MatrixUpdate(int rowno){ 
  
  if(rowno == 1){                 
                                  // Tlc.set(OUTPUT, BRIGHTNESS VALUE (0-4095)), general use of Tlc.set      
    Tlc.set(Ach, Aa);             // set Aa brightness to Ach OUTPUT(OUTPUT 0); 
    Tlc.set(Bch, Ba);             // set Ba brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Cch, Ca);             // set Ca brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Dch, Da);             // set Da brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Ech, Ea);             // set Ea brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Fch, Fa);             // set Fa brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Gch, Ga);             // set Ga brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Hch, Ha);             // set Ha brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Ich, Ia);             // set Ia brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(Jch, Ja);             // set Ja brightness to Bch OUTPUT(OUTPUT 1);
    Tlc.set(10, 0);               // set 0 brightness to OUTPUT 10, unused OUTPUT
    Tlc.set(11, 0);               // set 0 brightness to OUTPUT 11, unused OUTPUT
    Tlc.set(12, 0);               // set 0 brightness to OUTPUT 12, unused OUTPUT
    Tlc.set(13, 0);               // set 0 brightness to OUTPUT 13, unused OUTPUT
    Tlc.set(14, 0);               // set 0 brightness to OUTPUT 14, unused OUTPUT
    Tlc.set(15, 0);               // set 0 brightness to OUTPUT 15, unused OUTPUT
    
    digitalWrite(RowOne, HIGH);   // sets RowOne (pin 8) High (not active)--> Row one OFF
    digitalWrite(RowTwo, HIGH);   // sets RowTwo (pin 7) High (not active)--> Row two OFF
    digitalWrite(RowThree, HIGH); // sets RowThree (pin 6) High (not active)--> Row three OFF
    digitalWrite(RowFour, HIGH);  // sets RowFour (pin 5) High (not active)--> Row four OFF
    digitalWrite(RowFive, HIGH);  // sets RowFive (pin 4) High (not active)--> Row five OFF   
    Tlc.update();                 // writes the values for the LEDs brightness to the tlc
    delay(2);                     // give the tlc some time to let the value settle
    digitalWrite(RowOne, LOW);    // sets RowOne (pin 8) Low (active)--> Row one ON
  }
  
    if(rowno == 2){
    
  
    Tlc.set(Ach, Ab);             // same as if(rowno == 1) but we use different brightness, so we define LEDs in the second row
    Tlc.set(Bch, Bb);
    Tlc.set(Cch, Cb);
    Tlc.set(Dch, Db);    
    Tlc.set(Ech, Eb);
    Tlc.set(Fch, Fb);
    Tlc.set(Gch, Gb);
    Tlc.set(Hch, Hb);    
    Tlc.set(Ich, Ib);
    Tlc.set(Jch, Jb);
    Tlc.set(10, 0);
    Tlc.set(11, 0);
    Tlc.set(12, 0);
    Tlc.set(13, 0);
    Tlc.set(14, 0);
    Tlc.set(15, 0);
    
    digitalWrite(RowOne, HIGH);  // same as if(rowno==1)
    digitalWrite(RowTwo, HIGH);
    digitalWrite(RowThree, HIGH);
    digitalWrite(RowFour, HIGH);
    digitalWrite(RowFive, HIGH);
    Tlc.update();
    delay(2);
    digitalWrite(RowTwo, LOW);  // sets RowTwo (pin 7) Low (active)--> Row two ON
  }
  
  
  if(rowno == 3){
    
    Tlc.set(Ach, Ac);          // same as if(rowno == 1) but we use different brightness, so we define LEDs in the 3. row
    Tlc.set(Bch, Bc);
    Tlc.set(Cch, Cc);
    Tlc.set(Dch, Dc);    
    Tlc.set(Ech, Ec);
    Tlc.set(Fch, Fc);
    Tlc.set(Gch, Gc);
    Tlc.set(Hch, Hc);    
    Tlc.set(Ich, Ic);
    Tlc.set(Jch, Jc);
    Tlc.set(10, 0);
    Tlc.set(11, 0);
    Tlc.set(12, 0);
    Tlc.set(13, 0);
    Tlc.set(14, 0);
    Tlc.set(15, 0);
    
    digitalWrite(RowOne, HIGH);   // same as if(rowno==1)
    digitalWrite(RowTwo, HIGH);
    digitalWrite(RowThree, HIGH);
    digitalWrite(RowFour, HIGH);
    digitalWrite(RowFive, HIGH);
    Tlc.update();
    delay(2);
    digitalWrite(RowThree, LOW);   // sets RowThree (pin 6) Low (active)--> Row three ON 
  }
  
  
  if(rowno == 4){
    
    Tlc.set(Ach, Ad);              // same as if(rowno == 1) but we use different brightness, so we define LEDs in the 4. row
    Tlc.set(Bch, Bd);
    Tlc.set(Cch, Cd);
    Tlc.set(Dch, Dd);    
    Tlc.set(Ech, Ed);
    Tlc.set(Fch, Fd);
    Tlc.set(Gch, Gd);
    Tlc.set(Hch, Hd);    
    Tlc.set(Ich, Id);
    Tlc.set(Jch, Jd);
    Tlc.set(10, 0);
    Tlc.set(11, 0);
    Tlc.set(12, 0);
    Tlc.set(13, 0);
    Tlc.set(14, 0);
    Tlc.set(15, 0);
    
    digitalWrite(RowOne, HIGH);  // same as if(rowno==1)
    digitalWrite(RowTwo, HIGH);
    digitalWrite(RowThree, HIGH);
    digitalWrite(RowFour, HIGH);
    digitalWrite(RowFive, HIGH);
    Tlc.update();
    delay(2);
    digitalWrite(RowFour, LOW);  // sets RowFour (pin 5) Low (active)--> Row four ON
  }

 if(rowno == 5){
    
    Tlc.set(Ach, Ae);            // same as if(rowno == 1) but we use different brightness, so we define LEDs in the 5. row
    Tlc.set(Bch, Be);
    Tlc.set(Cch, Ce);
    Tlc.set(Dch, De);    
    Tlc.set(Ech, Ee);
    Tlc.set(Fch, Fe);
    Tlc.set(Gch, Ge);
    Tlc.set(Hch, He);    
    Tlc.set(Ich, Ie);
    Tlc.set(Jch, Je);
    Tlc.set(10, 0);
    Tlc.set(11, 0);
    Tlc.set(12, 0);
    Tlc.set(13, 0);
    Tlc.set(14, 0);
    Tlc.set(15, 0);
    
    digitalWrite(RowOne, HIGH);  // same as if(rowno==1)
    digitalWrite(RowTwo, HIGH);
    digitalWrite(RowThree, HIGH);
    digitalWrite(RowFour, HIGH);
    digitalWrite(RowFive, HIGH);
    Tlc.update();
    delay(2);
    digitalWrite(RowFive, LOW);  // sets RowFive (pin 4) Low (active)--> Row five ON
  }}
  
  void Eletter1(){               // here I start to create an animation which moves the letter "E" from the left side to the right side, so I create a static pic of "E" when it is on the far right side in Eletter1 
    Aa=bright;
    Ba=bright;
    Ca=bright;
    Ab=bright;
    Ac=bright; 
    Bc=bright;
    Cc=bright;
    Ad=bright;
    Ae=bright;
    Be=bright;
    Ce=bright;} 
  void Eletter2(){               // now we move each led brightness level to the next led to the right (for example Aa becomes Ba, Bc becomes Cc)
    Ba=bright;
    Ca=bright;
    Da=bright;
    Bb=bright;
    Bc=bright; 
    Cc=bright;
    Dc=bright;
    Bd=bright;
    Be=bright;
    Ce=bright;
    De=bright;} 
 void Eletter3(){                // now we continue this trend by always moving the led brightness value to the led to the right
    Ca=bright;
    Da=bright;
    Ea=bright;
    Cb=bright;
    Cc=bright; 
    Dc=bright;
    Ec=bright;
    Cd=bright;
    Ce=bright;
    De=bright;
    Ee=bright;} 
 void Eletter4(){                // we have 10 rows in total, so we must create 10 pics of "E" to let it move afterwards
    Da=bright;
    Ea=bright;
    Fa=bright;
    Db=bright;
    Dc=bright; 
    Ec=bright;
    Fc=bright;
    Dd=bright;
    De=bright;
    Ee=bright;
    Fe=bright;}
  void Eletter5(){
    Ea=bright;
    Fa=bright;
    Ga=bright;
    Eb=bright;
    Ec=bright; 
    Fc=bright;
    Gc=bright;
    Ed=bright;
    Ee=bright;
    Fe=bright;
    Ge=bright;}
   void Eletter6(){
    Fa=bright;
    Ga=bright;
    Ha=bright;
    Fb=bright;
    Fc=bright; 
    Gc=bright;
    Hc=bright;
    Fd=bright;
    Fe=bright;
    Ge=bright;
    He=bright;}
   void Eletter7(){
    Ga=bright;
    Ha=bright;
    Ia=bright;
    Gb=bright;
    Gc=bright; 
    Hc=bright;
    Ic=bright;
    Gd=bright;
    Ge=bright;
    He=bright;
    Ie=bright;}
   void Eletter8(){
    Ha=bright;
    Ia=bright;
    Ja=bright;
    Hb=bright;
    Hc=bright; 
    Ic=bright;
    Jc=bright;
    Hd=bright;
    He=bright;
    Ie=bright;
    Je=bright;}
   void Eletter9(){
    Ia=bright;
    Ja=bright;
    Aa=bright;
    Ib=bright;
    Ic=bright; 
    Jc=bright;
    Ac=bright;
    Id=bright;
    Ie=bright;
    Je=bright;
    Ae=bright;}
   void Eletter10(){            // you did everything right if you move the brightness value again and create a 11.pic which is identical to the 1.pic. And this is correct in this case
    Ja=bright;
    Aa=bright;
    Ba=bright;
    Jb=bright;
    Jc=bright; 
    Ac=bright;
    Bc=bright;
    Jd=bright;
    Je=bright;
    Ae=bright;
    Be=bright;}
    
   
    
  void reset(){                 // we set all LEDs to 0 brightness
  Aa = 0;
  Ba = 0;
  Ca = 0;
  Da = 0;
  Ea = 0;
  Fa = 0;
  Ga = 0;
  Ha = 0;
  Ia = 0;
  Ja = 0;

  Ab = 0;
  Bb = 0;
  Cb = 0;
  Db = 0;
  Eb = 0;
  Fb = 0;
  Gb = 0;
  Hb = 0;
  Ib = 0;
  Jb = 0;

  Ac = 0;
  Bc = 0;
  Cc = 0;
  Dc = 0;
  Ec = 0;
  Fc = 0;
  Gc = 0;
  Hc = 0;
  Ic = 0;
  Jc = 0;

  Ad = 0;
  Bd = 0;
  Cd = 0;
  Dd = 0;
  Ed = 0;
  Fd = 0;
  Gd = 0;
  Hd = 0;
  Id = 0;
  Jd = 0;

  Ae = 0;
  Be = 0;
  Ce = 0;
  De = 0;
  Ee = 0;
  Fe = 0;
  Ge = 0;
  He = 0;
  Ie = 0;
  Je = 0;}
  
  void pos1(){                   // simple animation of a wall moving from left to right
    Aa=bright;
    Ab=bright;
    Ac=bright;
    Ad=bright;
    Ae=bright;}
  void pos2(){
    Ba=bright;
    Bb=bright;
    Bc=bright;
    Bd=bright;
    Be=bright;}    
  void pos3(){
    Ca=bright;
    Cb=bright;
    Cc=bright;
    Cd=bright;
    Ce=bright;}    
  void pos4(){
    Da=bright;
    Db=bright;
    Dc=bright;
    Dd=bright;
    De=bright;}    
  void pos5(){
    Ea=bright;
    Eb=bright;
    Ec=bright;
    Ed=bright;
    Ee=bright;}    
  void pos6(){
    Fa=bright;
    Fb=bright;
    Fc=bright;
    Fd=bright;
    Fe=bright;}   
  void pos7(){
    Ga=bright;
    Gb=bright;
    Gc=bright;
    Gd=bright;
    Ge=bright;}    
  void pos8(){
    Ha=bright;
    Hb=bright;
    Hc=bright;
    Hd=bright;
    He=bright;}    
  void pos9(){
    Ia=bright;
    Ib=bright;
    Ic=bright;
    Id=bright;
    Ie=bright;}    
  void pos10(){
    Ja=bright;
    Jb=bright;
    Jc=bright;
    Jd=bright;
    Je=bright;}
    
  void sin1(){              // sine animation which only needs 8 columns, so I only need 8 static pics
  Ca=bright;
  Bb=bright;
  Db=bright;
  Ac=bright;
  Ec=bright;  
  Fd=bright;
  Hd=bright;
  Ge=bright;}
  void sin2(){
  Da=bright;
  Cb=bright;
  Eb=bright;
  Bc=bright;
  Fc=bright;  
  Gd=bright;
  Ad=bright;
  He=bright;}
  void sin3(){
  Ea=bright;
  Db=bright;
  Fb=bright;
  Cc=bright;
  Gc=bright;  
  Hd=bright;
  Bd=bright;
  Ae=bright;}
  void sin4(){
  Fa=bright;
  Eb=bright;
  Gb=bright;
  Dc=bright;
  Hc=bright;  
  Ad=bright;
  Cd=bright;
  Be=bright;}
  void sin5(){
  Ga=bright;
  Fb=bright;
  Hb=bright;
  Ec=bright;
  Ac=bright;  
  Bd=bright;
  Dd=bright;
  Ce=bright;}
  void sin6(){
  Ha=bright;
  Gb=bright;
  Ab=bright;
  Fc=bright;
  Bc=bright;  
  Cd=bright;
  Ed=bright;
  De=bright;} 
  void sin7(){
  Aa=bright;
  Hb=bright;
  Bb=bright;
  Gc=bright;
  Cc=bright;  
  Dd=bright;
  Fd=bright;
  Ee=bright;}    
  void sin8(){
  Ba=bright;
  Ab=bright;
  Cb=bright;
  Hc=bright;
  Dc=bright;  
  Ed=bright;
  Gd=bright;
  Fe=bright;}

void how(){      // static word "how"

Aa=bright;
Ab=bright;
Ac=bright;
Ad=bright;
Ae=bright;
Bc=bright;
Ca=bright;
Cb=bright;
Cc=bright;
Cd=bright;
Ce=bright;
Da=bright;
Db=bright;
Dc=bright;
Dd=bright;
De=bright;
Ea=bright;
Ee=bright;
Fa=bright;
Fb=bright;
Fc=bright;
Fd=bright;
Fe=bright;
Ga=bright;
Gb=bright;
Gc=bright;
Gd=bright;
Ge=bright;
Hd=bright;
Id=bright;
Ja=bright;
Jb=bright;
Jc=bright;
Jd=bright;
Je=bright;}
    

   
 
 
  
  
  
 
  
  
  
  
