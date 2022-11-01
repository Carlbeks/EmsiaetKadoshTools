#pragma once

#include <iostream>
#include <mmsystem.h>
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <mutex>
#include <exception>
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
#define ptrType reinterpret_cast
#define typetrans ptrType

#endif // !EMSIAETKADOSH_GRAND_SIMPLIFY

#define _in_		___NONE___	/*Input parameter												*/
#define _out_		___NONE___	/*Output target parameter										*/
#define _in_opt_	___NONE___	/*Optional input parameter										*/
#define _out_opt_	___NONE___	/*Optional output target parameter								*/
#define _pre_decl_	___NONE___	/*Declaration Only												*/
#define _decl_def_	___NONE___	/*Declaration and definition									*/
#define _def_only_	___NONE___	/*Definition Only												*/
#define $Overridable virtual	/*Function is overridable.										*/
#define $Override	override
#define $Overriding(expression) expression $Override

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

_pre_decl_ C Pointer;
_pre_decl_ C Object__;
_pre_decl_ template<typename Type_, typename TypeSelf__> C ObjectInterface__;
_pre_decl_ template<typename Type_, typename TypeSelf__> C Number__;
_pre_decl_ C Integar;
_pre_decl_ C Boolean;
_pre_decl_ C Character;
_pre_decl_ C ArrayBase;
_pre_decl_ template<typename Type_> C ArrayList;
_def_only_ C Pointer{
cpo:
	using pointer__ = v*;
cpi:
	pointer__ self_;
cpo:
	Pointer() {
		self_ = nullptr;
	}
	Pointer(pointer__ input) {
		self_ = input;
	}
	pointer__ self() {
		er self_;
	}
	pointer__ operator()() {
		er self_;
	}
};
_def_only_ C Object__{
cpk:
	Pointer selfp;
cpo:
	$Overridable std::string toString() {
		er "";
	}
	$Overridable Pointer getPointer() {
		er selfp;
	}
	$Overridable std::string PointerString() {
		er "";
	}
};
_def_only_ template<typename Type_, typename TypeSelf__> C ObjectInterface__ :virtual cpo Object__{
cpk:
	$Overridable v set(Pointer input) {
		*(Type_*)(selfp.self()) = *(Type_*)(input.self());
		er;
	}
cpo:
	$Overridable TypeSelf__ that() {
		logging.Output(LOG_ERROR, "[DynamicCastException] @ ObjectInterface__::that(), Unoverrode, dynamic_cast failure.");
		TypeSelf__* Er = {};
		try {
			Er = dynamic_cast<TypeSelf__*>(this);
		}
		catch (...) {
			throw;
			exit(1);
		}
		er* Er;
	}
	$Overridable Type_ self() {
		er* (Type_*)(selfp.self());
	}
};
_def_only_ template<typename Type_, typename TypeSelf__> C Number__ : virtual cpo Object__, virtual cpo ObjectInterface__<Type_, TypeSelf__>{
cpo:
	Number__(TypeSelf__ input) {
		selfp = new Type_;
		*(Type_*)(selfp()) = *(Type_*)(dynamic_cast<Object__*>(&input)->getPointer()());
	}
	Number__(Type_ input) {
		selfp = new Type_;
		*(Type_*)(selfp()) = input;
	}
	Number__() {
		selfp = new Type_;
	}
	static TypeSelf__ add(TypeSelf__ input1, TypeSelf__ input2) {
		TypeSelf__ Ret(*(Type_*)(input1.getPointer()()) + (*(Type_*)(input2.getPointer()())));
		er Ret;
	}
	static TypeSelf__ substract(TypeSelf__ input1, TypeSelf__ input2) {
		TypeSelf__ Ret(*(Type_*)(input1.getPointer()()) - (*(Type_*)(input2.getPointer()())));
		er Ret;
	}
	static TypeSelf__ multiply(TypeSelf__ input1, TypeSelf__ input2) {
		TypeSelf__ Ret(*(Type_*)(input1.getPointer()()) * (*(Type_*)(input2.getPointer()())));
		er Ret;
	}
	static TypeSelf__ divide(TypeSelf__ input1, TypeSelf__ input2) {
		TypeSelf__ Ret(*(Type_*)(input1.getPointer()()) / (*(Type_*)(input2.getPointer()())));
		er Ret;
	}
	$Overridable TypeSelf__ add(Type_ input) {
		*(Type_*)(selfp.self()) += input;
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ substract(Type_ input) {
		*(Type_*)(selfp.self()) -= input;
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ multiply(Type_ input) {
		*(Type_*)(selfp.self()) *= input;
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ divide(Type_ input) {
		*(Type_*)(selfp.self()) /= input;
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ add(TypeSelf__ input) {
		*(Type_*)(selfp.self()) += *(Type_*)(input.getPointer()());
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ substract(TypeSelf__ input) {
		*(Type_*)(selfp.self()) -= *(Type_*)(input.getPointer()());
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ multiply(TypeSelf__ input) {
		*(Type_*)(selfp.self()) *= *(Type_*)(input.getPointer()());
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ divide(TypeSelf__ input) {
		*(Type_*)(selfp.self()) /= *(Type_*)(input.getPointer()());
		er* dynamic_cast<TypeSelf__*>(this);
	}
	$Overridable TypeSelf__ clone() {
		TypeSelf__ Ret(*typetrans<Type_*>(selfp.self()));
		er Ret;
	}
};
_def_only_ C Integar : virtual cpo Number__<n, Integar>{
cpo:
	Integar divideRound(n input) {
		*(n*)(selfp.self()) /= input;
		er* this;
	}
	Integar divideRound(Integar input) {
		*(n*)(selfp.self()) /= *(n*)(input.selfp.self());
		er* this;
	}
	Integar divideRemain(n input) {
		*(n*)(selfp.self()) % input;
		er* this;
	}
	Integar divideRemain(Integar input) {
		*(n*)(selfp.self()) % *(n*)(input.selfp.self());
		er* this;
	}
	static Integar divideRound(n input1, n input2) {
		Integar ret(input1 / input2);
		er ret;
	}
	static Integar divideRound(Integar input1, Integar input2) {
		Integar ret(*(n*)(input1.getPointer()()) / (*(n*)(input2.getPointer()())));
		er ret;
	}
	static Integar divideRemain(n input1, n input2) {
		Integar ret(input1 % input2);
		er ret;
	}
	static Integar divideRemain(Integar input1, Integar input2) {
		Integar ret(*(n*)(input1.getPointer()()) % (*(n*)(input2.getPointer()())));
		er ret;
	}
	Integar() {

	}
	Integar(n input) {
		*(n*)(selfp.self()) = input;
	}
	Integar(Integar& input) {
		*(n*)(selfp.self()) = input.self();
	}
	Integar(const Integar& input) {
		Pointer ptr__ = input.selfp;
		*(n*)(selfp.self()) = *(n*)(ptr__.self());
	}
	Integar(c input) {
		if (input != NULL) {
			*(n*)(selfp.self()) = input;
		}
	}
	$Overriding(Integar that()) {
		er* this;
	}
	operator n() {
		er this->self();
	}
};

_def_only_ C ArrayBase{
cpk:
	Pointer list_;
	n layer_ = 0;
cpo:
	static const un3 _16 = 0, _256 = 1, _4096 = 2, _65536 = 3, _1048576 = 4, _16777216 = 5, _268435456 = 6, _4294967296 = 7;
	ArrayBase() {
		list_ = {};
	}
};
_def_only_ template<typename Type_> C ArrayList : cpo ArrayBase{
cpi:
	b onDelete() {
		if (layer_ == 0) {
			Type_** list__ = reinterpret_cast<Type_**>(list_.self());
			if (
				list__[0] == nullptr &&
				list__[1] == nullptr &&
				list__[2] == nullptr &&
				list__[3] == nullptr &&
				list__[4] == nullptr &&
				list__[5] == nullptr &&
				list__[6] == nullptr &&
				list__[7] == nullptr &&
				list__[8] == nullptr &&
				list__[9] == nullptr &&
				list__[10] == nullptr &&
				list__[11] == nullptr &&
				list__[12] == nullptr &&
				list__[13] == nullptr &&
				list__[14] == nullptr &&
				list__[15] == nullptr
				) {
				delete this;
				er true;
			}
		}
		else {
			ArrayList<Type_>** list__ = reinterpret_cast<ArrayList<Type_>**>(list_.self());
			if (
				list__[0] == nullptr &&
				list__[1] == nullptr &&
				list__[2] == nullptr &&
				list__[3] == nullptr &&
				list__[4] == nullptr &&
				list__[5] == nullptr &&
				list__[6] == nullptr &&
				list__[7] == nullptr &&
				list__[8] == nullptr &&
				list__[9] == nullptr &&
				list__[10] == nullptr &&
				list__[11] == nullptr &&
				list__[12] == nullptr &&
				list__[13] == nullptr &&
				list__[14] == nullptr &&
				list__[15] == nullptr
				) {
				delete this;
				er true;
			}
		}
		er false;
	}
	b remove_(un6 position, b isRelease) {
		n pos_ = Integar::divideRound(position, 16).self();
		n remain_ = Integar::divideRemain(position, 16).self();
		if (layer_ == 0) {
			Type_** list__ = reinterpret_cast<Type_**>(list_.self());
			if (list__[remain_] != nullptr) {
				delete list__[remain_];
				list__[remain_] = nullptr;
			}
		}
		else {
			ArrayList<Type_>** list__ = reinterpret_cast<ArrayList<Type_>**>(list_.self());
			if (list__[pos_] != nullptr) {
				if (list__[pos_]->remove_(remain_, isRelease)) list__[pos_] = nullptr;
			}
		}
		if (isRelease) {
			if (onDelete()) er true;
		}
		er false;
	}
cpo:
	ArrayList(un3 layer) {
		layer_ = layer;
		if (layer != 0) {
			list_ = new ArrayList<Type_>*[16] {};
		}
		else {
			list_ = new Type_ * [16] {};
		}
	}
	ArrayList() = delete;
	Type_ operator[](un6 position) {
		if (position < pow(16, layer_ + 1)) {
			n pos_ = Integar::divideRound(position, 16).self();
			n remain_ = (n)Integar::divideRemain(position, 16).self();
			if (layer_ == 0) {
				Type_** list__ = reinterpret_cast<Type_**>(list_.self());
				if (list__[remain_] == nullptr) {
					logging.Output(LOG_WARN, "[NullPointerException] @ ArrayList::operator[], Position in the ArrayList requesting is non existent.");
					Type_ ret{};
					er ret;
				}
				else {
					er* (list__[remain_]);
				}
			}
			else {
				ArrayList<Type_>** list__ = reinterpret_cast<ArrayList<Type_>**>(list_.self());
				if (list__[pos_] == nullptr) {
					logging.Output(LOG_WARN, "[NullPointerException] @ ArrayList::operator[], Position in the ArrayList requesting is non existent.");
					Type_ ret{};
					er ret;
				}
				else {
					er(*(list__[pos_]))[remain_];
				}
			}
		}
		else {
			logging.Output(LOG_WARN, "[OverflowException] @ ArrayList::operator[], Position in the ArrayList is out of the maximun length.");
			er NULL;
		}
	}
	void set(un6 position, Type_ value) {
		if (position < pow(16, layer_ + 1)) {
			n pos_ = Integar::divideRound(position, 16).self();
			n remain_ = Integar::divideRemain(position, 16).self();
			if (layer_ == 0) {
				Type_** list__ = reinterpret_cast<Type_**>(list_.self());
				if (list__[remain_] == nullptr) {
					list__[remain_] = new Type_;
				}
				*(list__[remain_]) = value;
			}
			else {
				ArrayList<Type_>** list__ = reinterpret_cast<ArrayList<Type_>**>(list_.self());
				if (list__[pos_] == nullptr) {
					list__[pos_] = new ArrayList<Type_>(layer_ - 1);
				}
				list__[pos_]->set(remain_, value);
			}
		}
		else {
			logging.Output(LOG_WARN, "[OverflowException] @ ArrayList::set(), Position in the ArrayList is out of the maximun length.");
		}
	}
	v remove(un6 position, b isRelease = false) {
		if (position < pow(16, layer_ + 1)) {
			n pos_ = Integar::divideRound(position, 16).self();
			n remain_ = Integar::divideRemain(position, 16).self();
			if (layer_ == 0) {
				Type_** list__ = reinterpret_cast<Type_**>(list_.self());
				if (list__[remain_] != nullptr) {
					delete list__[remain_];
					list__[remain_] = nullptr;
				}
			}
			else {
				ArrayList<Type_>** list__ = reinterpret_cast<ArrayList<Type_>**>(list_.self());
				if (list__[pos_] != nullptr) {
					list__[pos_]->remove_(remain_, isRelease);
				}
			}
			if (isRelease) {
				onDelete();
			}
		}
		else {
			logging.Output(LOG_WARN, "[OverflowException] @ ArrayList::remove(), Position in the ArrayList is out of the maximun length.");
		}
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
// Class:
// cpo, cpi:		[members]					anyform_
// cpk:				[members]					classname(__)anyform[membername]
// 
// 
// 
// 