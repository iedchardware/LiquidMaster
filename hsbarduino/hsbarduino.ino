//github/MAINAKMONDAL98
int redPin = 3;
int greenPin = 9;
int bluePin = 10;

float col[3];
float hue = 0.0;
  char c,d;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 // setColor(hsv2rgb(hue, 1.0, 1.0, col));
  //delay(50);
//  Serial.println(d);
 if(Serial.available()>0){
  c=Serial.read();
  //d=c;
  Serial.println(c);
 /* if(c=='s'){
 // hue += 0.10;
   hue=0.0;
   setColor(hsv2rgb(hue, 1.0, 1.0, col));
  while (hue <= 0.30){
    setColor(hsv2rgb(hue, 1.0, 1.0, col));
    hue=hue+0.10;
    delay(10);
    }
  }
  */
 if(c=='h'){

 hue=0.61;
    for(int x=0;x<38;x++){
      setColor(hsv2rgb(hue, 1.0, 1.0, col));
        Serial.println(hue);
        hue=hue+0.01;
        delay(100);
    }
 } 

 else if(c=='s'){

    hue=0.16;
    for(int x=0;x<41;x++){
      setColor(hsv2rgb(hue, 1.0, 1.0, col));
        Serial.println(hue);
        hue=hue+0.01;
        delay(100);
    }
 }


 else if(c=='n'){

    hue=0.00;
    for(int x=0;x<16;x++){
      setColor(hsv2rgb(hue, 1.0, 1.0, col));
        Serial.println(hue);
        hue=hue+0.01;
        delay(100);
    }
 }

/*
 
   if(c=='s'){
  
for (float hue=0.0;hue < 0.30;hue++){
    setColor(hsv2rgb(hue, 1.0, 1.0, col));
    Serial.println(hue);
    delay(10);
    }
  } 
   if(c=='s'){
  
for (float hue=0.31;hue < 0.59;hue++){
    setColor(hsv2rgb(hue, 1.0, 1.0, col));
    Serial.println(hue);
    delay(10);
    }
  } 

  
  /*
  if(c=='n'){
 // hue += 0.10;
   hue=.31;
   setColor(hsv2rgb(hue, 1.0, 1.0, col));
  while (hue <= 0.60){
    setColor(hsv2rgb(hue, 1.0, 1.0, col));
    hue=hue+0.10;
    delay(10);
    }
  }
  
  Serial.println(hue);*/
}
else{  setColor(hsv2rgb(hue, 0, 1.0, col));}
/*
  if(c=='h'){

    hue=0.61;
    for(int x=0;x<38;x++){
      setColor(hsv2rgb(hue, 1.0, 1.0, col));
        Serial.println(hue);
        hue=hue+0.01;
        delay(100);
    }
 } 

 else if(c=='s'){

    hue=0.16;
    for(int x=0;x<41;x++){
      setColor(hsv2rgb(hue, 1.0, 1.0, col));
        Serial.println(hue);
        hue=hue+0.01;
        delay(100);
    }
 }


 else if(c=='n'){

    hue=0.00;
    for(int x=0;x<16;x++){
      setColor(hsv2rgb(hue, 1.0, 1.0, col));
        Serial.println(hue);
        hue=hue+0.01;
        delay(100);
    }
 } 
}

Serial.println(d);*/

}

void setColor(float *rgb) {
  analogWrite(redPin, (int)((1.0 - rgb[0]) * 255));
  analogWrite(greenPin, (int)((1.0 - rgb[1]) * 255));
  analogWrite(bluePin, (int)((1.0 - rgb[2]) * 255));  
}

// HSV->RGB conversion based on GLSL version
// expects hsv channels defined in 0.0 .. 1.0 interval
float fract(float x) { return x - int(x); }

float mix(float a, float b, float t) { return a + (b - a) * t; }

float step(float e, float x) { return x < e ? 0.0 : 1.0; }

float* hsv2rgb(float h, float s, float b, float* rgb) {
  rgb[0] = b * mix(1.0, constrain(abs(fract(h + 1.0) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
  rgb[1] = b * mix(1.0, constrain(abs(fract(h + 0.6666666) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
  rgb[2] = b * mix(1.0, constrain(abs(fract(h + 0.3333333) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
  return rgb;
}

float* rgb2hsv(float r, float g, float b, float* hsv) {
  float s = step(b, g);
  float px = mix(b, g, s);
  float py = mix(g, b, s);
  float pz = mix(-1.0, 0.0, s);
  float pw = mix(0.6666666, -0.3333333, s);
  s = step(px, r);
  float qx = mix(px, r, s);
  float qz = mix(pw, pz, s);
  float qw = mix(r, px, s);
  float d = qx - min(qw, py);
  hsv[0] = abs(qz + (qw - py) / (6.0 * d + 1e-10));
  hsv[1] = d / (qx + 1e-10);
  hsv[2] = qx;
  return hsv;
}
