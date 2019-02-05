#include "stdafx.h"
#include "Email.h"
#include <string>
#include "easendmailobj.tlh"
#include <conio.h>
using namespace EASendMailObjLib;


Email::Email()
{
}


Email::~Email()
{
}

void Email:: sendEmail(string email)
{
	_bstr_t em;
	em = email.c_str();
	
	::CoInitialize(NULL);

	IMailPtr oSmtp = NULL;
	oSmtp.CreateInstance("EASendMailObj.Mail");
	oSmtp->LicenseCode = _T("TryIt");
	//Don't change this 
	oSmtp->FromAddr = _T("projuni78@gmail.com");
	//This can be changed
	oSmtp->AddRecipientEx( _T("javerianadeem03@gmail.com"), 0);
	oSmtp->AddRecipientEx(_T("qandeel.asif@gmail.com "), 0);
	oSmtp->AddRecipientEx(_T("khatri.yasir@gmail.com "), 0);
	//
	oSmtp->Subject = _T("Your Food receipt");

	oSmtp->BodyText = _T("Your Bill in the attachment");
	//The bill file loc
	if (oSmtp->AddAttachment(_T("E:\\OPP\\ProjectFinalFinal\\ProjectFinalFinal\\bill.dat")) != 0)
	{
		_tprintf(_T("Failed to add attachment with error: %s\r\n"),
			(const TCHAR*)oSmtp->GetLastErrDescription());
	}

	oSmtp->ServerAddr = _T("smtp.gmail.com");

	oSmtp->ServerPort = 587;

	oSmtp->SSL_init();
	//Dont change these
	oSmtp->UserName = _T("projuni78@gmail.com");
	oSmtp->Password = _T("javeriaqandeelyasir");

	_tprintf(_T("Start to send email via gmail account ..."));

	if (oSmtp->SendMail() == 0)
	{
		_tprintf(_T("email was sent successfully!\r\n"));
	}
	else
	{
		_tprintf(_T("failed to send email with the following error: %s\r\n"),
			(const TCHAR*)oSmtp->GetLastErrDescription());
	}

	if (oSmtp != NULL)
		oSmtp.Release();
	_getch();
}