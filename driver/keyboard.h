/*
 * キーボード
 */

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <Queue.h>

const int kPortKeyData = 0x0060;
const int kPortKeyStatus = 0x0064;
const int kPortKeyCmd = 0x0064;
const int kKeyStatusSendNotReady = 0x02;
const int kKeyCmdWriteMode = 0x60;
const int kKBCMode = 0x47;
const int kKeyCmdLED = 0xed;

class KeyboardController {
private:
	static unsigned char asciiTable[];
	static unsigned char asciiShiftTable[];
	static int shift;
	static bool alt;
	static int leds;
	static Queue<int> *cmd;
	static int cmdWait;
	static TaskQueue *queue;

public:
	friend void IntHandler21(int *esp);
	static void Main();
	static void Decode(unsigned char code);
	static void wait();
};

#endif
