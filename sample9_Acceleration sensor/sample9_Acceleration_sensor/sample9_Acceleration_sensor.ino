// accel_practice_sample1

const int accel_pin[] = { 0, 1, 2 };

int accel_val[] = { 0, 0, 0 };

void setup() {
  Serial.begin( 9600 );
}

void loop() {
  byte buffer[2];

  for ( int i = 0; i < 3; i++ ) {
    accel_val[i] = analogRead( accel_pin[i] );
  }

  if ( Serial.available() > 0 ) {
    for ( int i = 0; i < 3; i++ ) {
      buffer[0] = byte( accel_val[i] );
      buffer[1] = byte( accel_val[i] >> 8 );
      Serial.write( buffer, 2 );
    }
    Serial.read();
  }
}


