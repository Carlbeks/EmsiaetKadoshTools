#pragma once


#include <iostream>
#include <mmsystem.h>
#include <Windows.h>
#include <stdio.h>
#include <mutex>
//#include <chrono>
#pragma comment(lib,"winmm.lib")
#pragma warning(disable:4996)

#ifndef EMSIAETKADOSH_GRAND
#define EMSIAETKADOSH_GRAND

#ifndef EMSIAETKADOSH_GRAND_VK
#define EMSIAETKAODHS_GRAND_VK
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
#endif // !EMSIAETKADOSH_GRAND_VK

#ifndef EMSIAETKADOSH_GRAND_IM
#define EMSIAETKADOSH_GRAND_IM
#ifndef IM_QUIT
#define IM_QUIT 0
#endif // !IM_QUIT
#ifndef IM_CMD
#define IM_CMD 1
#define CMD_LOG 1
#define CMD_STEP 2
#define CMD_BANBLOCK 3
#define CMD_SHUTLOOP 4
#endif // !IM_CMD
#endif // !EMSIAETKADOSH_GRAND_IM


#ifndef EMSIAETKADOSH_GRAND_SIMPLIFY
#define EMSIAETKADOSH_GRAND_SIMPLIFY
#define n int // int
typedef signed char sn3;
typedef signed short sn4;
typedef signed int sn5;
typedef signed __int64 sn6;
typedef unsigned char un3;
typedef unsigned short un4;
typedef unsigned int un5;
typedef unsigned __int64 un6;
#define f float // float
#define v void // void
#define b bool // bool
#define S struct // struct
#define C class // class
#define c char // char
#define wct wchar_t // wchar_t
#define cpo public // public
#define cpi private // private
#define cpk protected // protected
#define er return // return
#define er1 return 1
#define er0 return 0
#define nMax 0b1111111111111111111111111111111111111111111111111111111111111111
#define nMin 0b0000000000000000000000000000000000000000000000000000000000000000
#define def(_Return_Type_,_pFunc_,_Parameters_) _Return_Type_(*_pFunc_)_Parameters_
#endif // !EMSIAETKADOSH_GRAND_SIMPLIFY

#define _in_ 
#define _out_
#define _in_opt_
#define _out_opt_

#endif // !EMSIAETKADOSH_GRAND


enum logrankLOG {
	LOG_ALL, LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL, LOG_OFF
};
enum cmdtypeCMD {
	CMD_stdout,CMD_stdin
};
C LOGGING{
cpo:
	logrankLOG logrank = LOG_DEBUG;
	FILE* SetLogFile(const c* name = R"(D:\EmsiaetKadosh\O\ProjectSaves\EKTools\EmsiaetKadoshDesktopTool-pre3\log.log)") {
		AllocConsole();
		er freopen(name, "a+", stdout);
	}
	v Output(logrankLOG tgtlogrank, std::string content) {
		if (tgtlogrank >= logrank) {
			switch (tgtlogrank)
			{
			case LOG_ALL:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000111);
				std::cout << "[EKDT] " << timeGetTime() << " [all]   >>> " << content << std::endl;
				break;
			case LOG_TRACE:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001001);
				std::cout << "[EKDT] " << timeGetTime() << " [trace] >>> " << content << std::endl;
				break;
			case LOG_DEBUG:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001010);
				std::cout << "[EKDT] " << timeGetTime() << " [debug] >>> " << content << std::endl;
				break;
			case LOG_INFO:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001111);
				std::cout << "[EKDT] " << timeGetTime() << " [info]  >>> " << content << std::endl;
				break;
			case LOG_WARN:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000110);
				std::cout << "[EKDT] " << timeGetTime() << " [warn]  >>> " << content << std::endl;
				break;
			case LOG_ERROR:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001100);
				std::cout << "[EKDT] " << timeGetTime() << " [error] >>> " << content << std::endl;
				break;
			case LOG_FATAL:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000100);
				std::cout << "[EKDT] " << timeGetTime() << " [FATAL] >>> " << content << std::endl;
				break;
			case LOG_OFF:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b01001111);
				std::cout << "[EKDT] " << timeGetTime() << " [OFF]   >>> " << content << std::endl;
				break;
			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000110);
				std::cout << "[EKDT] " << timeGetTime() << " [Unknown] > " << content << std::endl;
				break;
			}
		}
		er;
	}
	v SetOutputColor(logrankLOG tgtlogrank) {
		switch (tgtlogrank)
		{
		case LOG_ALL:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000111); break;
		case LOG_TRACE:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001001); break;
		case LOG_DEBUG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001010); break;
		case LOG_INFO:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001111); break;
		case LOG_WARN:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000110); break;
		case LOG_ERROR:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00001100); break;
		case LOG_FATAL:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000100); break;
		case LOG_OFF:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b01001111); break;
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b00000110); break;
		}
	}
} logging;
v ShowCmd(cmdtypeCMD stdStatus) {
	AllocConsole();
	switch (stdStatus)
	{
	case CMD_stdout:
		freopen("CONOUT$", "a+", stdout);
		break;
	case CMD_stdin:
		freopen("CONIN$", "a+", stdin);
		break;
	default:
		break;
	}
	er;
}
std::string JoinString(_in_ std::string str1, _in_ std::string str2) {
	std::string str = str1 + str2;
	er str;
};
std::string IntToString_OCT(_in_ n target, _out_opt_ std::string* string = nullptr) {
	def(std::string, ___getStr, (n)) = [](n input)->std::string {
		if (input) {
			if (input >= 5) {
				if (input >= 7) {
					if (input >= 9) {
						if (input > 9) {
							er"x";
						}
						else {
							er"9";
						}
					}
					if (input == 8) {
						er"8";
					}
					else {
						er"7";
					}
				}
				if (input == 6) {
					er"6";
				}
				else {
					er"5";
				}
			}
			else {
				if (input >= 3) {
					if (input == 4) {
						er"4";
					}
					else {
						er"3";
					}
				}
				else {
					if (input >= 1) {
						if (input == 2) {
							er"2";
						}
						else {
							er"1";
						}
					}
					else {
						er"v";
					}
				}
			}
		}
		else {
			er"0";
		}
	};
	std::string Er = "";
	n temp = 0;
	b first_pos = false;
	temp = (n)(target / 10000000000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 10000000000000000000;
	}
	temp = (n)(target / 1000000000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 1000000000000000000;
	}
	temp = (n)(target / 100000000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 100000000000000000;
	}
	temp = (n)(target / 10000000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 10000000000000000;
	}
	temp = (n)(target / 1000000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 1000000000000000;
	}
	temp = (n)(target / 100000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 100000000000000;
	}
	temp = (n)(target / 10000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 10000000000000;
	}
	temp = (n)(target / 1000000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 1000000000000;
	}
	temp = (n)(target / 100000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 100000000000;
	}
	temp = (n)(target / 10000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 10000000000;
	}
	temp = (n)(target / 1000000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 1000000000;
	}
	temp = (n)(target / 100000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 100000000;
	}
	temp = (n)(target / 10000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 10000000;
	}
	temp = (n)(target / 1000000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 1000000;
	}
	temp = (n)(target / 100000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 100000;
	}
	temp = (n)(target / 10000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 10000;
	}
	temp = (n)(target / 1000);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 1000;
	}
	temp = (n)(target / 100);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 100;
	}
	temp = (n)(target / 10);
	if (temp || first_pos) {
		first_pos = true;
		Er += ___getStr(temp);
		target -= temp * 10;
	}
	temp = target;
	Er += ___getStr(temp);
	er Er;
}

C ekThreadBlocker{
cpi:
	b ifstop = false;
	b ifloop = true;
	b ifnrelease = false;
	n banlevel = 0;
cpo:
	n GetBanlevel() {
		er banlevel;
	}
	v SetBanlevel(n _banlevel) {
		banlevel = _banlevel;
		er;
	}
	n block(n _banlevel = 1, n sleeptime = 1) {
		if (ifstop || _banlevel <= banlevel) {
			er1;
		}
		else {
			ifstop = true;
			while (ifloop) {
				Sleep(sleeptime);
			}
			ifnrelease = false;
			ifstop = false;
			ifloop = true;
		}
		er0;
	}
	n release(n sleeptime = 1) {
		if (ifstop) {
			ifloop = false;
			ifnrelease = true;
			un3 looptimes = 0;
			while (ifnrelease) {
				if (looptimes >= 500) {
					er1;
				}
				Sleep(sleeptime);
				looptimes++;
			};
			er0;
		}
		else {
			er1;
		}
	}
} StepThreadBlocker;

C ekMessage{
cpi:
	b is_active = false;
	C EKMSGBUFFER {
	cpi:
		b isfree = true;
	cpo:
		un3 command = 0;
		un3 fmParam = 0;
		un3 idParam = 0;
		n ctParam = 0;
		v operator()(un3 _command, un3 _fmparam, un3 _idparam, n _ctparam) {
			command = _command;
			fmParam = _fmparam;
			idParam = _idparam;
			ctParam = _ctparam;
			isfree = false;
		}
		v operator-() {
			isfree = true;
		}
		v operator--() {
			isfree = true;
		}
		b isBusy() {
			er !isfree;
		}
		b isFree() {
			er isfree;
		}
	};
cpo:
	C EKMSG {
	cpo:
		un3 command = 0;
		un3 fmParam = 0;
		un3 idParam = 0;
		n ctParam = 0;
		v operator<=(EKMSGBUFFER ekmsgbuffer) {
			command = ekmsgbuffer.command;
			fmParam = ekmsgbuffer.fmParam;
			idParam = ekmsgbuffer.idParam;
			ctParam = ekmsgbuffer.ctParam;
			er;
		}
	};
cpi:
	un3 posr = 0;
	un3 posw = 0;
	LOGGING loggingIn;
	std::mutex mutex_lock_read;
	std::mutex mutex_lock_write;
	EKMSGBUFFER ekmsgs[256];
	std::string* ekmsg_logging_strings[256];
	def(n, Proc, (un3, un3, un3, n)) = [](un3, un3, un3, n)->n { er0; };
	def(b, _GetInnerMessage, (EKMSG*, EKMSGBUFFER*, un3*)) = [](EKMSG*, EKMSGBUFFER*, un3*)->b { er0; };
	def(b, _PeekInnerMessage, (EKMSG*, EKMSGBUFFER*, un3*)) = [](EKMSG*, EKMSGBUFFER*, un3*)->b { er0; };
	v ForceExitInnerMessage() {
		is_active = false;
		_GetInnerMessage = [](EKMSG*, EKMSGBUFFER*, un3*)->b { er0; };
		_PeekInnerMessage = [](EKMSG*, EKMSGBUFFER*, un3*)->b { er0; };
		er;
	}
cpo:
	v Init(
		_in_ def(n, MsgProc, (un3, un3, un3, n))
	) {
		Proc = MsgProc;
		_PeekInnerMessage = [](EKMSG* pekmsg, EKMSGBUFFER* ekmsgs, un3* posr)->b {
			if (ekmsgs[*posr].isFree()) {
				er false;
			}
			if (ekmsgs[*posr].command /* == IM_QUIT */) {
				*pekmsg <= ekmsgs[*posr];
				--ekmsgs[*posr];
				*posr = (*posr == 255) ? 0 : (*posr + 1);
				er true;
			};
			--ekmsgs[*posr];
			er false;
		};
		_GetInnerMessage = [](EKMSG* pekmsg, EKMSGBUFFER* ekmsgs, un3* posr)->b {
			while (ekmsgs[*posr].isFree()) {
				Sleep(1);
			}
			if (ekmsgs[*posr].command /* == IM_QUIT */) {
				*pekmsg <= ekmsgs[*posr];
				--ekmsgs[*posr];
				*posr = (*posr == 255) ? 0 : (*posr + 1);
				er true;
			};
			--ekmsgs[*posr];
			er false;
		};
		is_active = true;
		er;
	}
	b isActive() {
		er is_active;
	}
	v PostInnerMessage(
		_in_ un3 command,
		_in_ un3 fmparam,
		_in_ un3 idparam,
		_in_ n ctparam
	) {
		mutex_lock_write.lock();
		if (ekmsgs[posw].isFree()) {
			ekmsgs[posw](command, fmparam, idparam, ctparam);
			posw = (posw == 255) ? 0 : (posw + 1);
		}
		else {
			if (!is_active) {
				PostQuitMessage(0);
				ForceExitInnerMessage();
				logging.Output(LOG_OFF, "Crashed!");
				logging.Output(LOG_OFF, "-- Crash Report --");
				logging.Output(LOG_OFF, "Inner message pool overflow.");
				logging.Output(LOG_OFF, "Please submit the crash report with all this log file.");
			}
		}
		mutex_lock_write.unlock();
		er;
	}
	v PostInnerMessageLogU(
		_in_ logrankLOG logrank,
		_in_ std::string content
	) {
		mutex_lock_write.lock();
		if (ekmsgs[posw].isFree()) {
			ekmsg_logging_strings[posw] = new std::string;
			*(ekmsg_logging_strings[posw]) = content;
			ekmsgs[posw](IM_CMD, CMD_LOG, posw, logrank);
			logging.Output(LOG_INFO, JoinString("Post", IntToString_OCT(posw)));
			posw = (posw == 255) ? 0 : (posw + 1);
		}
		else {
			if (!is_active) {
				PostQuitMessage(0);
				ForceExitInnerMessage();
				logging.Output(LOG_OFF, "Crashed!");
				logging.Output(LOG_OFF, "-- Crash Report --");
				logging.Output(LOG_OFF, "Inner message pool overflow.");
				logging.Output(LOG_OFF, "Please submit the crash report with all this log file.");
			}
		}
		mutex_lock_write.unlock();
		er;
	}
	b GetInnerMessageU(
		_out_ EKMSG* pekmsg
	){
		mutex_lock_read.lock();
		while (ekmsgs[posr].isFree()) {
			Sleep(1);
		}
		if (ekmsgs[posr].command /* == IM_QUIT */) {
			*pekmsg <= ekmsgs[posr];
			--ekmsgs[posr];
			posr = (posr == 255) ? 0 : (posr + 1);
			mutex_lock_read.unlock();
			er true;
		};
		--ekmsgs[posr];
		mutex_lock_read.unlock();
		er false;
	}
	b GetInnerMessageS(
		_out_ EKMSG* pekmsg
	) {
		mutex_lock_read.lock();
		b ER = _GetInnerMessage(pekmsg, ekmsgs, &posr);
		mutex_lock_read.unlock();
		er ER;
	}
	b PeekInnerMessageU(
		_out_ EKMSG* pekmsg
	) {
		mutex_lock_read.lock();
		if (ekmsgs[posr].isFree()) {
			mutex_lock_read.unlock();
			er false;
		}
		if (ekmsgs[posr].command /* == IM_QUIT */) {
			*pekmsg <= ekmsgs[posr];
			--ekmsgs[posr];
			posr = (posr == 255) ? 0 : (posr + 1);
			mutex_lock_read.unlock();
			er true;
		};
		--ekmsgs[posr];
		mutex_lock_read.unlock();
		er false;
	}
	b PeekInnerMessageS(
		_out_ EKMSG* pekmsg
	) {
		mutex_lock_read.lock();
		b ER = _PeekInnerMessage(pekmsg, ekmsgs, &posr);
		mutex_lock_read.unlock();
		er ER;
	}
	v DispatchInnerMessage(
		_in_ EKMSG* pekmsg
	){
		if (Proc(pekmsg->command, pekmsg->fmParam, pekmsg->idParam, pekmsg->ctParam)) {
			FinalInnerMessage(pekmsg->command, pekmsg->fmParam, pekmsg->idParam, pekmsg->ctParam);
		}
		logging.Output(LOG_WARN, JoinString("Processing InnerMessage ",IntToString_OCT(posr)));
		er;
	}
	v FinalInnerMessage(
		_in_ un3 _command,
		_in_ un3 _fmparam,
		_in_ un3 _idparam,
		_in_ n _ctparam
	) {
		switch (_command)
		{
		case IM_CMD:
			switch (_fmparam)
			{
			case CMD_LOG:
				loggingIn.Output((logrankLOG)_ctparam, *ekmsg_logging_strings[_idparam]);
				delete ekmsg_logging_strings[_idparam];
				break;
			case CMD_STEP:
				StepThreadBlocker.release();
				break;
			case CMD_BANBLOCK:
				StepThreadBlocker.SetBanlevel(1);
				break;
			case CMD_SHUTLOOP:
				break;
			default:
				break;
			}
		default:
			break;
		}
		er;
	}
} InnerMessage;
typedef ekMessage::EKMSG EKMSG;
