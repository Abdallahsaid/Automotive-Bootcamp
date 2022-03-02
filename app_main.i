# 1 "app_main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "app_main.c"
# 1 "app_main.h" 1



extern void vidFunc(short int *u16FuncArgPtr);
# 2 "app_main.c" 2

char u8InitGLobalVar = 2;
static long int u32NonInitStaticGlobalVar;
const short int u16ConstGlobalVar = 3;


char arr[5] __attribute__((section(".sprints"))) = {0,1,2,3,4};


void main(void)
{
 short int u16LocVar = 4;
 static char u8InitStaticLocVar = 5;
 if(u16ConstGlobalVar == 3)
 {
  u32NonInitStaticGlobalVar = 6;
  vidFunc(&u16LocVar);
  arr[0]++;
 }
 else
 {
  u32NonInitStaticGlobalVar = 7;
  arr[1]++;

 }
 while(1)
 {

 }
}
