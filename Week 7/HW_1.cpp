const int AXIAL_X = A0;  		// 宣告水平電位計連接到A0接腳
const int AXIAL_Y = A1;  		// 宣告垂直電位計連接到A1接腳
const int scan[3] = {10,11,12};  	// 宣告掃描信號連接到10~12接腳
const int G1 = 13;  			// 宣告G1控制信號連接到13接腳
const int row[8] = {2,3,4,5,6,7,8,9};	// 宣告顯視信號連接到2~9接腳
int X = 0, Y = 0, Column, Row;		// 宣告整數變數
// 初始設定
void setup() {   
  	for(int i=0;i<3;i++) 	pinMode(scan[i],OUTPUT);// 設定scan接腳為輸出接腳
  	pinMode(G1,OUTPUT);		// 設定G1接腳為輸出接腳
  	for(int i=0;i<8;i++) 	pinMode(row[i],OUTPUT);	// 設定row接腳為輸出接腳
}
// 主程式
void loop() {
	X = analogRead(AXIAL_X);	// 讀取水平位置(0~1023)
	Y = analogRead(AXIAL_Y);	// 讀取垂直位置(0~1023)
	Column = X/128;	// X軸轉換刻度
	Row = 7 - Y/128;		// Y軸轉換刻度
	switch (Column) {	// 轉換/輸出掃描信號
		case 0: 
			digitalWrite(scan[2],0);
			digitalWrite(scan[1],0);
			digitalWrite(scan[0],0); 
			break;
		case 1: 
			digitalWrite(scan[2],0);
			digitalWrite(scan[1],0);
			digitalWrite(scan[0],1); 
			break;
		case 2: 
			digitalWrite(scan[2],0);
			digitalWrite(scan[1],1);
			digitalWrite(scan[0],0); 
			break;
		case 3: 
			digitalWrite(scan[2],0);
			digitalWrite(scan[1],1);
			digitalWrite(scan[0],1); 
			break;
		case 4: 
			digitalWrite(scan[2],1);
			digitalWrite(scan[1],0);
			digitalWrite(scan[0],0); 
			break;
		case 5: 
			digitalWrite(scan[2],1);
			digitalWrite(scan[1],0);
			digitalWrite(scan[0],1); 
			break;
		case 6: 
			digitalWrite(scan[2],1);
			digitalWrite(scan[1],1);
			digitalWrite(scan[0],0); 
			break;
		case 7: 
			digitalWrite(scan[2],1);
			digitalWrite(scan[1],1);
			digitalWrite(scan[0],1); 
			break;
	}	
	for ( int i=0;i<8;i++)  digitalWrite(row[i],0);	// 關閉顯示信號
	digitalWrite(row[Row],1);			// 輸出顯示信號
	digitalWrite(G1, 1);				// 啟動顯示
}
