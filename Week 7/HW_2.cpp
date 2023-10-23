const int POT = A0;  		// 宣告水平電位計連接到A0接腳
const int scan[3] = {6,9,10};  	// 宣告掃描信號連接到6、9、10接腳
const int G1 = 11;  		// 宣告G1控制信號連接到11接腳
const int seg[8] = {2,3,4,5,7,8,12,13};
const int HW_2[11][8] = {
  {0xFF,0xFF,0x83,0x7D,0x7D,0x7D,0x83,0xFF}, //0
  {0xFF,0xFF,0x7B,0x01,0x01,0x7F,0xFF,0xFF}, //1
  {0xFF,0xFF,0xFF,0x99,0x99,0xFF,0xFF,0xFF}, //:
  {0xFF,0xFF,0xBB,0x7D,0x6D,0x6D,0x93,0xFF}, //3
  {0xFF,0xFF,0x93,0x6D,0x6D,0x6D,0x93,0xFF}, //8
  {0xFF,0xE7,0xE7,0x81,0x81,0xE7,0xE7,0xFF},  //+
  {0xFF,0xFF,0x7B,0x3D,0x5D,0x6D,0x73,0xFF}, //2
  {0xFF,0xFF,0xC7,0xDB,0xDD,0x01,0xDF,0xFF}, //4
  {0xFF,0xE7,0xE7,0x81,0x81,0xE7,0xE7,0xFF},  //+
  {0xFF,0xFF,0xC7,0xDB,0xDD,0x01,0xDF,0xFF}, //4
  {0xFF,0xFF,0xBB,0x7D,0x6D,0x6D,0x93,0xFF} //3
};
     
int X = 0, col, row;	// 宣告整數變數
// 初始設定
void setup() {   
   for(int i=0;i<3;i++) pinMode(scan[i],OUTPUT); // 設定scan接腳為輸出接腳
   pinMode(G1,OUTPUT);				 // 設定G1接腳為輸出接腳
   for(int i=0;i<8;i++) pinMode(seg[i],OUTPUT);  // 設定row接腳為輸出接腳
}
// 主程式
void loop() {
   for (int num=0;num<11;num++)	{ 	// 順序顯示10個數字
      for (int dup=0;dup<60;dup++) {	// 每個數字重覆掃描60次
      // 16ms*60=960ms=0.96s
         for (int col=0;col<8;col++) {	// 每個數字8條掃描線
            digitalWrite(G1,0);		// 關閉掃描線(防殘影)
            row=HW_2[num][col];		// 讀取顯示信號
            for (int i=0;i<8;i++) {	// 輸出顯示信號
               if (row&1) digitalWrite(seg[i],0);
               else digitalWrite(seg[i],1);
               row>>=1;			// 下一個位元
            }
            scanOut(col);	        // 輸出顯示信號
            X = analogRead(POT);	// 讀取水平電位計(0~1023)
            analogWrite(G1, X/4);	// 設定亮度
            delay(2);			// 持續點亮2ms
         } 
      } 
   } 
} 
// ========轉換/輸出掃描信號函數========
void scanOut(int sel) {
   switch (sel) {	// 轉換/輸出掃描信號
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
}
