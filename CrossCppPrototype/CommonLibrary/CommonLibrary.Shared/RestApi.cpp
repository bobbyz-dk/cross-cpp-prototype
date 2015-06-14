#include "pch.h"
#include "RestApi.h"
#include "log.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/URI.h"

namespace RestApiSpace
{
	//using namespace Poco::Net;

	RestApi::RestApi()
	{
	}


	RestApi::~RestApi()
	{
	}

	void RestApi::PostComment(Comment comment)
	{
		logdebug("RestApi", "Comment: " + comment.ToString());
		
		/*try
		{*/
			/*const Poco::URI uri("http://localhost:2403");
			//Poco::Net::HTTPClientSession session("http://localhost", 2403);
			Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
			//Poco::Net::HTTPClientSession session();
			
			Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_POST, "/comment");
			req.setContentType("application/x-www-form-urlencoded\r\n");
			req.setKeepAlive(true);

			std::string reqBody("");
			req.setContentLength(reqBody.length());

			//Poco::Net::HTTPBasicCredentials cred("???", "???");
			//cred.authenticate(req);
			session.sendRequest(req) << reqBody;
			Poco::Net::HTTPResponse res;
			std::istream& rs = session.receiveResponse(res);
			std::string resp;*/
		/*}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}*/

	}
}