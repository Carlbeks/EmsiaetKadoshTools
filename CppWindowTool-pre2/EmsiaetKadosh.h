#pragma once


#ifndef EMSIAETKADOSH_GRAND
#define EMSIAETKADOSH_GRAND 0

#define VK_A 65
#define VK_B 66
#define VK_C 67
#define VK_D 68
#define VK_E 69
#define VK_F 70
#define VK_G 71
#define VK_H 72
#define VK_I 73
#define VK_J 74
#define VK_K 75
#define VK_L 76
#define VK_M 77
#define VK_N 78
#define VK_O 79
#define VK_P 80
#define VK_Q 81
#define VK_R 82
#define VK_S 83
#define VK_T 84
#define VK_U 85
#define VK_V 86
#define VK_W 87
#define VK_X 88
#define VK_Y 89
#define VK_Z 90

#define n int // int
#define f float // float
#define v void // void
#define c const // const
#define b bool // bool
#define S struct // struct
#define C class // class
#define wct wchar_t // wchar_t
#define cpo public // public
#define cpi private // private
#define cpk protected // protected
#define er return // return
#define a ; // ;
#define er1 return 1;
#define er0 return 0;
#define aer ;return // ;return;
#define aer1 ;return 1;
#define aer0 ;return 0;
#define ew switch
#define eta break;
#define nMax 0b1111111111111111111111111111111111111111111111111111111111111111
#define nMin 0b0000000000000000000000000000000000000000000000000000000000000000
typedef n(*pIntF)();
#define pne pIntF
typedef v(*pVoidF)();
#define pve pVoidF
#define pf(type,pFunc,_in_) type(*pFunc)_in_
#endif // !EMSIAETKADOSH_GRAND

C ekThreadBlocker{
cpi:
	b ifstop = false;
	b ifloop = true;
	b ifrelease = true;
cpo:
	n block(n sleeptime = 50) {
		ifrelease = false;
		if (ifstop) {
			er1
		}
		else {
			ifstop = true;
		}
		while (ifloop) {
			Sleep(sleeptime);
		}
		ifrelease = true;
		ifstop = false;
		ifloop = true;
		er0
	}
	n release() {
		ifloop = false;
		while (!ifrelease);
		er0
	}
};