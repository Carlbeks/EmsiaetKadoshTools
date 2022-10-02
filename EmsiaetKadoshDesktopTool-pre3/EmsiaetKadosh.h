#pragma once

#include <iostream>
#include <mmsystem.h>
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <mutex>
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
#ifndef IM_ACT
#define IM_ACT 2
#ifndef ACT_MOUSE
#define ACT_MOUSE 1
#define MOUSE_L_D 1
#define MOUSE_L_U 2
#define MOUSE_R_D 3
#define MOUSE_R_U 4
#define MOUSE_M_D 5
#define MOUSE_M_U 6
#define MOUSE_SCROLL_D 7
#define MOUSE_SCROLL_U 8
#define MOUSE_ENTER 9
#define MOUSE_LEAVE 10
#endif // !ACT_MOUSE
#endif // !IM_ACT
#endif // !EMSIAETKADOSH_GRAND_IM


#ifndef EMSIAETKADOSH_GRAND_SIMPLIFY
#define EMSIAETKADOSH_GRAND_SIMPLIFY
#define n int /*int*/
typedef signed char sn3;
typedef signed short sn4;
typedef signed int sn5;
typedef signed __int64 sn6;
typedef unsigned char un3;
typedef unsigned short un4;
typedef unsigned int un5;
typedef unsigned __int64 un6;
#define f		float			/*float		*/
#define v		void			/*void		*/
#define b		bool			/*bool		*/
#define S		struct			/*struct	*/
#define C		class			/*class		*/
#define c		char			/*char		*/
#define wct		wchar_t			/*wchar_t	*/
#define cpo		public			/*public	*/
#define cpi		private			/*private	*/
#define cpk		protected		/*protected	*/
#define er		return			/*return	*/
#define er1		return 1		/*return 1	*/
#define er0		return 0		/*return 0	*/
#define nMax	0b1111111111111111111111111111111111111111111111111111111111111111
#define nMin	0b0000000000000000000000000000000000000000000000000000000000000000
#define ___NONE___
#define def(_Return_Type_,_pFunc_,_Parameters_) _Return_Type_(*_pFunc_)_Parameters_ // Defines FunctionPointers

#endif // !EMSIAETKADOSH_GRAND_SIMPLIFY

#define _in_		___NONE___	/*Input parameter												*/
#define _out_		___NONE___	/*Output target parameter										*/
#define _in_opt_	___NONE___	/*Optional input parameter										*/
#define _out_opt_	___NONE___	/*Optional output target parameter								*/
#define _pre_decl_	___NONE___	/*Declaration Only												*/
#define _decl_def_	___NONE___	/*Declaration and definition									*/
#define _def_only_	___NONE___	/*Definition Only												*/

#endif // !EMSIAETKADOSH_GRAND


_decl_def_ enum logrankLOG {
	LOG_ALL, LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL, LOG_OFF
};
_decl_def_ enum cmdtypeCMD {
	CMD_stdout,CMD_stdin
};
_decl_def_ C ekLogging{
cpi:
	std::mutex mutex_lock;
cpo:
	logrankLOG logrank = LOG_DEBUG;
	FILE* SetLogFile(const c* name = R"(D:\EmsiaetKadosh\O\ProjectSaves\EKTools\EmsiaetKadoshDesktopTool-pre3\log.log)") {
		AllocConsole();
		er freopen(name, "a+", stdout);
	}
	v Output(logrankLOG tgtlogrank, std::string content) {
		mutex_lock.lock();
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
		mutex_lock.unlock();
		er;
	}
	v SetOutputColor(logrankLOG tgtlogrank) {
		mutex_lock.lock();
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
		mutex_lock.unlock();
		er;
	}
} logging;
_decl_def_ v ShowCmd(cmdtypeCMD stdStatus) {
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
_decl_def_ std::string JoinString(_in_ std::string str1, _in_ std::string str2) {
	std::string str = str1 + str2;
	er str;
};
_decl_def_ std::string IntToString_10(_in_ n target, _out_opt_ std::string* string = nullptr) {
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
// std::string UIntToString_OCT(_in_ n target, _out_opt_ std::string* string = nullptr);

_decl_def_ C ekThreadBlocker{
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
	v releaseAll() {
		banlevel = INT_MAX;
		release();
		er;
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
_decl_def_ C ekMessage{
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
				logging.Output((logrankLOG)_ctparam, *ekmsg_logging_strings[_idparam]);
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
			break;
		case IM_QUIT:
			break;
		default:
			break;
		}
		er;
	}
} InnerMessage;
_decl_def_ typedef ekMessage::EKMSG ekMsg;

_decl_def_ template<typename type_> C ekArray{
#define ekArray_pos_to_g_(pos____) \
un3 g8 = pos____ & 15;\
un3 g7 = pos____ >> 4;\
un3 g6 = g7 >> 4; g7 = g7 & 15;\
un3 g5 = g6 >> 4; g6 = g6 & 15;\
un3 g4 = g5 >> 4; g5 = g5 & 15;\
un3 g3 = g4 >> 4; g4 = g4 & 15;\
un3 g2 = g3 >> 4; g3 = g3 & 15;\
un3 g1 = (g2 >> 4) & 15; g2 = g2 & 15;
#define ekArray_alloc \
if (pra_[g1]) {\
	if (pra_[g1][g2]) {\
		if (pra_[g1][g2][g3]) {\
			if (pra_[g1][g2][g3][g4]) {\
				if (pra_[g1][g2][g3][g4][g5]) {\
					if (pra_[g1][g2][g3][g4][g5][g6]) {\
						if (pra_[g1][g2][g3][g4][g5][g6][g7]) {\
							if (!pra_[g1][g2][g3][g4][g5][g6][g7][g8]) {\
								pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
							}\
						}\
						else {\
							pra_[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];\
							pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
						}\
					}\
					else {\
						pra_[g1][g2][g3][g4][g5][g6] = new p2_[16];\
						pra_[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];\
						pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
					}\
				}\
				else {\
					pra_[g1][g2][g3][g4][g5] = new p3_[16];\
					pra_[g1][g2][g3][g4][g5][g6] = new p2_[16];\
					pra_[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];\
					pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
				}\
			}\
			else {\
				pra_[g1][g2][g3][g4] = new p4_[16];\
				pra_[g1][g2][g3][g4][g5] = new p3_[16];\
				pra_[g1][g2][g3][g4][g5][g6] = new p2_[16];\
				pra_[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];\
				pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
			}\
		}\
		else {\
			pra_[g1][g2][g3] = new p5_[16];\
			pra_[g1][g2][g3][g4] = new p4_[16];\
			pra_[g1][g2][g3][g4][g5] = new p3_[16];\
			pra_[g1][g2][g3][g4][g5][g6] = new p2_[16];\
			pra_[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];\
			pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
		}\
	}\
	else {\
		pra_[g1][g2] = new p6_[16];\
		pra_[g1][g2][g3] = new p5_[16];\
		pra_[g1][g2][g3][g4] = new p4_[16];\
		pra_[g1][g2][g3][g4][g5] = new p3_[16];\
		pra_[g1][g2][g3][g4][g5][g6] = new p2_[16];\
		pra_[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];\
		pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
	}\
}\
else {\
	pra_[g1] = new p7_[16];\
	pra_[g1][g2] = new p6_[16];\
	pra_[g1][g2][g3] = new p5_[16];\
	pra_[g1][g2][g3][g4] = new p4_[16];\
	pra_[g1][g2][g3][g4][g5] = new p3_[16];\
	pra_[g1][g2][g3][g4][g5][g6] = new p2_[16];\
	pra_[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];\
	pra_[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;\
}
cpi:
	_pre_decl_ using p9_ = type_*********;
	_pre_decl_ using p8_ = type_********;
	_pre_decl_ using p7_ = type_*******;
	_pre_decl_ using p6_ = type_******;
	_pre_decl_ using p5_ = type_*****;
	_pre_decl_ using p4_ = type_****;
	_pre_decl_ using p3_ = type_***;
	_pre_decl_ using p2_ = type_**;
	_pre_decl_ using p1_ = type_*;
	_pre_decl_ using ty_ = type_;
	_pre_decl_ p9_ pra_;
	_decl_def_ un5 position = 0;
	_decl_def_ un3 status = 0;
	_pre_decl_ C TRANS;
cpo:
	// Main functions
	_decl_def_ n add(_in_ type_ add_) {
		ekArray_pos_to_g_(position)
		ekArray_alloc
		*(pra_[g1][g2][g3][g4][g5][g6][g7][g8]) = add_;
		er position++;
	}
	_decl_def_ n cut() {
		ekArray_pos_to_g_((position-1))
		delete pra_[g1][g2][g3][g4][g5][g6][g7][g8];
		er --position;
	}
	_decl_def_ n skip(_in_ un5 skip_pos_ = 1) {
		position += skip_pos_;
		er position;
	}
	_decl_def_ n getPosition() {
		er position;
	}
	_decl_def_ b find(_in_ un5 pos_) {
		ekArray_pos_to_g_(pos_)
		if(pra_[g1]) {
			if (pra_[g1][g2]) {
				if (pra_[g1][g2][g3]) {
					if (pra_[g1][g2][g3][g4]) {
						if (pra_[g1][g2][g3][g4][g5]) {
							if (pra_[g1][g2][g3][g4][g5][g6]) {
								if (pra_[g1][g2][g3][g4][g5][g6][g7]) {
									if (!pra_[g1][g2][g3][g4][g5][g6][g7][g8]) {
										er false;
									}
								}
								else {
									er false;
								}
							}
							else {
								er false;
							}
						}
						else {
							er false;
						}
					}
					else {
						er false;
					}
				}
				else {
					er false;
				}
			}
			else {
				er false;
			}
		}
		else {
			er false;
		}
		er true;
	}
	_decl_def_ b assign(_in_ un5 pos_, _in_ ty_ target_) {
		ekArray_pos_to_g_(pos_)
		ekArray_alloc
		*(pra_[g1][g2][g3][g4][g5][g6][g7][g8]) = target_;
		er true;
	}
	_decl_def_ b del(_in_ un5 pos_) {
		if (find(pos_)) {
			ekArray_pos_to_g_(pos_)
			delete pra_[g1][g2][g3][g4][g5][g6][g7][g8];
			er true;
		}
		else {
			er false;
		}
	}
	// Operators
	_decl_def_ type_ operator[](_in_ un5 pos_) {
		ekArray_pos_to_g_(pos_)
		er* (pra_[g1][g2][g3][g4][g5][g6][g7][g8]);
	}
	_decl_def_ TRANS set;
	// Constructors and Destructors
	_decl_def_ ekArray() : position { 0 }, status{ 1 }, set{ &pra_ } {
		pra_ = new p8_[16]{};
		er;
	}
	_decl_def_ ~ekArray() {
		status = 0;
		er;
	}
cpi:
	_def_only_ C TRANS{
	cpo:
		_pre_decl_ p9_ * pra_p_;
		_pre_decl_ ty_ target_;
		_pre_decl_ un5 position;
		_decl_def_ un3 status = 0;
		_decl_def_ TRANS(p9_* pra_p__) : pra_p_{ pra_p__ } {}
		_decl_def_ b operator=(ty_ target__) {
			if (status & 1) {
				ekArray_pos_to_g_(position)
				if ((*pra_p_)[g1]) {
					if ((*pra_p_)[g1][g2]) {
						if ((*pra_p_)[g1][g2][g3]) {
							if ((*pra_p_)[g1][g2][g3][g4]) {
								if ((*pra_p_)[g1][g2][g3][g4][g5]) {
									if ((*pra_p_)[g1][g2][g3][g4][g5][g6]) {
										if ((*pra_p_)[g1][g2][g3][g4][g5][g6][g7]) {
											if (!(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8]) {
												(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
											}
										}
										else {
											(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
											(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
										}
									}
									else {

										(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
										(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
										(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
									}
								}
								else {

									(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
									(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
									(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
									(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
								}
							}
							else {

								(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
								(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
								(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
								(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
								(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
							}
						}
						else {
							(*pra_p_)[g1][g2][g3] = new p5_[16];
							(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
							(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
							(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
							(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
							(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
						}
					}
					else {

						(*pra_p_)[g1][g2] = new p6_[16];
						(*pra_p_)[g1][g2][g3] = new p5_[16];
						(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
						(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
						(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
						(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
						(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
					}
				}
				else {

					(*pra_p_)[g1] = new p7_[16];
					(*pra_p_)[g1][g2] = new p6_[16];
					(*pra_p_)[g1][g2][g3] = new p5_[16];
					(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
					(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
					(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
					(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
					(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
				}
				* ((*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8]) = target__;
				position = 0;
				er true;
			}
			else {
				target_ = target__;
				status = 2;
			}
			er false;
		}
		_decl_def_ TRANS operator[](_in_ un5 pos_) {
			if (status & 2) {
				ekArray_pos_to_g_(pos_)
				if ((*pra_p_)[g1]) {
					if ((*pra_p_)[g1][g2]) {
						if ((*pra_p_)[g1][g2][g3]) {
							if ((*pra_p_)[g1][g2][g3][g4]) {
								if ((*pra_p_)[g1][g2][g3][g4][g5]) {
									if ((*pra_p_)[g1][g2][g3][g4][g5][g6]) {
										if ((*pra_p_)[g1][g2][g3][g4][g5][g6][g7]) {
											if (!(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8]) {
												(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
											}
										}
										else {
											(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
											(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
										}
									}
									else {

										(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
										(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
										(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
									}
								}
								else {

									(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
									(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
									(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
									(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
								}
							}
							else {

								(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
								(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
								(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
								(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
								(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
							}
						}
						else {
							(*pra_p_)[g1][g2][g3] = new p5_[16];
							(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
							(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
							(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
							(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
							(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
						}
					}
					else {

						(*pra_p_)[g1][g2] = new p6_[16];
						(*pra_p_)[g1][g2][g3] = new p5_[16];
						(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
						(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
						(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
						(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
						(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
					}
				}
				else {

					(*pra_p_)[g1] = new p7_[16];
					(*pra_p_)[g1][g2] = new p6_[16];
					(*pra_p_)[g1][g2][g3] = new p5_[16];
					(*pra_p_)[g1][g2][g3][g4] = new p4_[16];
					(*pra_p_)[g1][g2][g3][g4][g5] = new p3_[16];
					(*pra_p_)[g1][g2][g3][g4][g5][g6] = new p2_[16];
					(*pra_p_)[g1][g2][g3][g4][g5][g6][g7] = new p1_[16];
					(*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8] = new ty_;
				}
				*((*pra_p_)[g1][g2][g3][g4][g5][g6][g7][g8]) = target_;
				target_ = {};
				er true;
			}
			else {
				position = pos_;
				status = 1;
			}
			er* this;
		}
		_decl_def_ TRANS operator()() {
			position = 0;
			target_ = {};
			status = 0;
			er* this;
		}
	};
#undef ekArray_pos_to_g_
#undef ekArray_alloc
};
_decl_def_ template<typename type_> C ekArray12{
#define ekArray_pos_to_g_(pos____) \
un3 g3 = pos____ & 15;\
un3 g2 = pos____ >> 4;\
un3 g1 = g2 >> 4 & 15;\
g2 = g2 & 15;
cpi:
	_pre_decl_ using p4_ = type_****;
	_pre_decl_ using p3_ = type_***;
	_pre_decl_ using p2_ = type_**;
	_pre_decl_ using p1_ = type_*;
	_pre_decl_ using ty_ = type_;
	_decl_def_ p4_ pra_;
	_decl_def_ un4 position;
	_decl_def_ un3 status;
	_pre_decl_ C TRANS;
cpo:
	// Main functions
	_decl_def_ n add(_in_ ty_ add_) {
		ekArray_pos_to_g_(position)
		if (pra_[g1]) {
			if (pra_[g1][g2]) {
				if (!pra_[g1][g2][g3]) {
					pra_[g1][g2][g3] = new ty_;
				}
			}
			else {
				pra_[g1][g2] = new p1_[16]{};
				pra_[g1][g2][g3] = new ty_;
			}
		}
		else {
			pra_[g1] = new p2_[16]{};
			pra_[g1][g2] = new p1_[16]{};
			pra_[g1][g2][g3] = new ty_;
		}
		*(pra_[g1][g2][g3]) = add_;
		er position++;
	}
	_decl_def_ n addnew() {
		ekArray_pos_to_g_(position)
		if (pra_[g1]) {
			if (pra_[g1][g2]) {
				if (!pra_[g1][g2][g3]) {
					pra_[g1][g2][g3] = new ty_;
				}
			}
			else {
				pra_[g1][g2] = new p1_[16]{};
				pra_[g1][g2][g3] = new ty_;
			}
		}
		else {
			pra_[g1] = new p2_[16]{};
			pra_[g1][g2] = new p1_[16]{};
			pra_[g1][g2][g3] = new ty_;
		}
		er position++;
	}
	_decl_def_ n cut() {
		ekArray_pos_to_g_((position-1))
		delete pra_[g1][g2][g3];
		er --position;
	}
	_decl_def_ n skip(_in_ n skip_pos_ = 1) {
		position += skip_pos_;
		er position;
	}
	_decl_def_ n getPosition() {
		er position;
	}
	_decl_def_ b find(_in_ n pos_) {
		if (pos_ < 0 or pos_ > 0xfff) {
			er false;
		}
		ekArray_pos_to_g_(pos_)
		if (pra_[g1]) {
			if (pra_[g1][g2]) {
				if (pra_[g1][g2][g3]) {
					er true;
				}
			}
		}
		er false;
	}
	_decl_def_ b assign(_in_ n pos_, _in_ ty_ target_) {
		if (pos_ < 0 or pos_ > 0xfff) {
			er false;
		}
		ekArray_pos_to_g_(pos_)
		if (pra_[g1]) {
			if (pra_[g1][g2]) {
				if (!pra_[g1][g2][g3]) {
					pra_[g1][g2][g3] = new ty_;
				}
			}
			else {
				pra_[g1][g2] = new p1_[16]{};
				pra_[g1][g2][g3] = new ty_;
			}
		}
		else {
			pra_[g1] = new p2_[16]{};
			pra_[g1][g2] = new p1_[16]{};
			pra_[g1][g2][g3] = new ty_;
		}
		*(pra_[g1][g2][g3]) = target_;
		er true;
	}
	_decl_def_ b assignnew(_in_ n pos_) {
		if (pos_ < 0 or pos_ > 0xfff) {
			er false;
		}
		ekArray_pos_to_g_(pos_)
		if (pra_[g1]) {
			if (pra_[g1][g2]) {
				if (!pra_[g1][g2][g3]) {
					pra_[g1][g2][g3] = new ty_;
				}
			}
			else {
				pra_[g1][g2] = new p1_[16]{};
				pra_[g1][g2][g3] = new ty_;
			}
		}
		else {
			pra_[g1] = new p2_[16]{};
			pra_[g1][g2] = new p1_[16]{};
			pra_[g1][g2][g3] = new ty_;
		}
		er true;
	}
	_decl_def_ b del(_in_ n pos_) {
		if (pos_ < 0 or pos_ > 0xfff) {
			er false;
		}
		ekArray_pos_to_g_(pos_)
		if (pra_[g1]) {
			if (pra_[g1][g2]) {
				if (pra_[g1][g2][g3]) {
					delete pra_[g1][g2][g3];
					er true;
				}
			}
		}
		er false;
	}
	// Operators
	_decl_def_ ty_ operator[](_in_ n pos_) {
		ekArray_pos_to_g_(pos_)
		er* (pra_[g1][g2][g3]);
	}
	_decl_def_ TRANS set;
	// Constructor & Destrucor
	_decl_def_ ekArray12() : position{ 0 }, status{ 1 }, set{ &pra_ } {
		pra_ = new p3_[16]{};
		er;
	}
	_decl_def_ ~ekArray12() { status = 0; er; }
cpi:
	_def_only_ C TRANS{
	cpo:
		_pre_decl_ p4_ * pra_p_;
		_pre_decl_ ty_ target_;
		_pre_decl_ n position;
		_decl_def_ un3 status = 0;
		_decl_def_ TRANS(p4_* pra_p__) : pra_p_{ pra_p__ } {}
		_decl_def_ b operator=(ty_ target__) {
			if (status & 1) {
				ekArray_pos_to_g_(position)
				if ((*pra_p_)[g1]) {
					if (( * pra_p_)[g1][g2]) {
						if (!(* pra_p_)[g1][g2][g3]) {
							(* pra_p_)[g1][g2][g3] = new ty_;
						}
					}
					else {
						(*pra_p_)[g1][g2] = new p1_[16]{};
						(*pra_p_)[g1][g2][g3] = new ty_;
					}
				}
				else {
					(*pra_p_)[g1] = new p2_[16]{};
					(*pra_p_)[g1][g2] = new p1_[16]{};
					(*pra_p_)[g1][g2][g3] = new ty_;
				}
				*((*pra_p_)[g1][g2][g3]) = target__;
				position = 0;
				er true;
			}
			else {
				target_ = target__;
				status = 2;
			}
			er false;
		}
		_decl_def_ TRANS operator[](_in_ un5 pos_) {
			if (status & 2) {
				ekArray_pos_to_g_(pos_)
				if ((*pra_p_)[g1]) {
					if ((*pra_p_)[g1][g2]) {
						if (!(*pra_p_)[g1][g2][g3]) {
							(*pra_p_)[g1][g2][g3] = new ty_;
						}
					}
					else {
						(*pra_p_)[g1][g2] = new p1_[16]{};
						(*pra_p_)[g1][g2][g3] = new ty_;
					}
				}
				else {
					(*pra_p_)[g1] = new p2_[16]{};
					(*pra_p_)[g1][g2] = new p1_[16]{};
					(*pra_p_)[g1][g2][g3] = new ty_;
				}
				*((*pra_p_)[g1][g2][g3]) = target_;
				target_ = {};
				er* this;
			}
			else {
				position = pos_;
				status = 1;
			}
			er* this;
		}
		_decl_def_ TRANS operator()() {
			position = 0;
			target_ = {};
			status = 0;
			er* this;
		}
	};
#undef ekArray_pos_to_g_
};
_decl_def_ C ekTypeConverter{
cpi:
	ekArray12<v* (*)(v*,v*,n)> pfuncs;
	ekArray12<c*> pchars;
	ekArray12<ekArray12<v* (*)(v*, v*, n)>> pfunc2;
	un5 count = 0;
cpo:
	ekTypeConverter() {
		pchars.add(const_cast<c*>(typeid(n).name()));
		pchars.add(const_cast<c*>(typeid(f).name()));
		pchars.add(const_cast<c*>(typeid(v).name()));
		pchars.add(const_cast<c*>(typeid(b).name()));
		pchars.add(const_cast<c*>(typeid(c).name()));
		count = pchars.add(const_cast<c*>(typeid(wct).name()));
		er;
	}
	n Define(const c* pchar_, const n size_) {
		count = pchars.add(const_cast<c*>(pchar_));
		er count;
	}
	template<typename Output_, typename Input_>
	Output_ Convert(
		_in_	Input_		input_,
		_out_	Output_*	output_,
		_in_	n			if_return_to_output__
	) {
		n input_typecode_ = -1;
		const c* input_typename_ = typeid(Input_).name();
		for (n i = 0; i <= count; i++) {
			if (pchars[i] == input_typename_) {
				input_typecode_ = i;
				break;
			}
		}
		n output_typecode_ = -1;
		const c* output_typename_ = typeid(Output_).name();
		for (n i = 0; i <= count; i++) {
			if (pchars[i] == output_typename_) {
				output_typecode_ = i;
				break;
			}
		}
		er 0;
	}
};
//
// ÃüÃûÔ¼¶¨
// 
// #define global:	const						GLOBAL_CONST
// global:			class struct union			ekClassStructUnion
// global:			enum						enumNameENUM
// global:			enum{elements}				ENUM_ELEMENTS
// global:			var							GlobalVars
// global:			functions					f_FunctionName
// local:			var							anyform_
// 
// 
//