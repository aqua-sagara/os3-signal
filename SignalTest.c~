#include <stdio.h>
#include <signal.h>
#include "unistd.h"
//プロトタイプ宣言を適宜
void SignalHandler(int );
int main() {

  int i;

  //シグナルハンドラ関数を登録する
  //コマンド(% kill -USR1 "プロセスID")などにより シグナルSIGUSR1が送信されたとき 
  //シグナルハンドラ関数SignalHandlerが呼び出されるようになる
  signal(SIGUSR1, SignalHandler);

  for (i=0; ; ++i) {
    sleep(1); //すごい勢いで出力され重くなるので わざと1秒ずつ待っています
    printf("%d\n", i);
  }

  return 0;
}

// signal SIGUSR1 handler
void SignalHandler(int code) {

  printf("signal received\n");

  //シグナルハンドラ関数の再登録
  signal(SIGUSR1, SignalHandler);

}
