// data_plot_2byte_3data

import processing.serial.*;

Serial port;

int[] y_axes = { 230, 130, 30 };

boolean draw_flag = true;

int t = 0;
int[] data = { 0, 0, 0 };
int[] cali = { 0, 0, 0 };

void draw_axis() {
  stroke( 0, 0, 0 );
  line( 0, y_axes[0], width, y_axes[0] );
  stroke( 0, 0, 255 );
  line( 0, y_axes[1], width, y_axes[1] );
  stroke( 255, 0, 0 );
  line( 0, y_axes[2], width, y_axes[2] );
}

void plot_data( int data, char c ) {
  if ( c == 'r' ) stroke( 255, 0, 0 );
  if ( c == 'g' ) stroke( 0, 255, 0 );
  if ( c == 'b' ) stroke( 0, 0, 255 );
  strokeWeight( 2 );
  point( t, y_axes[0] - map( data, 0, 1024, 0, y_axes[0] - y_axes[2] ) );
  strokeWeight( 1 );
}

void setup() {
  size( 500, 260 );
  port = new Serial( this, Serial.list()[0], 9600 );
}

void draw() {
  if ( draw_flag ) {
    if ( t == 0 ) {
      background( 255 );
      draw_axis();
    }

    plot_data(data[0], 'r');
    plot_data(data[1], 'g');
    plot_data(data[2], 'b');

    t = (t+1) % width;
  }

  for ( int i = 0; i < 3; i++ ) {
    println( data[i] );
  }
  println();
}

void mouseClicked() {
  draw_flag = !draw_flag;
}

void keyPressed() {
  if ( key == 's' ) port.write( '*' );
  if ( key == 'c' ) {
    for ( int i = 0; i < 3; i++ ) {
      cali[i] = data[i] - 1024/2;
    }
    cali[2] = cali[2] - 1024/5;
  }
}

void serialEvent( Serial p ) {
  if ( port.available() > 5 ) {
    for ( int i = 0; i < 3; i++ ) {
      data[i] = port.read() + port.read() * 256 - cali[i];
    }
    port.write( '*' );
  }
}
  
