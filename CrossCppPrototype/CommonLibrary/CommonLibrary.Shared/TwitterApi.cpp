//#include "pch.h"
#include "TwitterApi.h"

namespace twitter
{
	using namespace std;

	TwitterApi::TwitterApi()
	{

	}

	TwitterApi::~TwitterApi()
	{}

	string TwitterApi::LoadLastTweet(string screenName)
	{
		//return "NOT IMPLEMENTED!";
		twitCurl twitterObj;
		std::string tmpStr, tmpStr2;
		std::string replyMsg;
		char tmpBuf[1024];

		/* Set twitter username and password */
		twitterObj.setTwitterUsername("bobbyzdk");
		twitterObj.setTwitterPassword("8f1alQwR)8e$");

		/* OAuth flow begins */
		/* Step 0: Set OAuth related params. These are got by registering your app at twitter.com */
		twitterObj.getOAuth().setConsumerKey(std::string("goqwJWBRzDjgqyzckBN1zXk7z"));
		twitterObj.getOAuth().setConsumerSecret(std::string("8KfuNwB9aTfBRze1HoAc0vLQeJq6DqBhkwTDMvH8CVx8FFunNX"));

		/* Step 1: Check if we alredy have OAuth access token from a previous run */
		std::string myOAuthAccessTokenKey("zWBbsoyw2FU1RfagmIKsozSkYe3jmboUBtm4ghiX");
		std::string myOAuthAccessTokenSecret("6tRjNPLbOuHuGjFIieGriOjqa2kMdQoi5JI2ZWTPBEy47");
		std::ifstream oAuthTokenKeyIn;
		std::ifstream oAuthTokenSecretIn;

		oAuthTokenKeyIn.open("twitterClient_token_key.txt");
		oAuthTokenSecretIn.open("twitterClient_token_secret.txt");

		if (myOAuthAccessTokenKey.size() && myOAuthAccessTokenSecret.size())
		{
			/* If we already have these keys, then no need to go through auth again */
			printf("\nUsing:\nKey: %s\nSecret: %s\n\n", myOAuthAccessTokenKey.c_str(), myOAuthAccessTokenSecret.c_str());

			twitterObj.getOAuth().setOAuthTokenKey(myOAuthAccessTokenKey);
			twitterObj.getOAuth().setOAuthTokenSecret(myOAuthAccessTokenSecret);
		}
		else
		{
			/* Step 2: Get request token key and secret */
			std::string authUrl;
			twitterObj.oAuthRequestToken(authUrl);

			twitterObj.oAuthHandlePIN(authUrl);
			
			/* Step 4: Exchange request token with access token */
			twitterObj.oAuthAccessToken();

			/* Step 5: Now, save this access token key and secret for future use without PIN */
			twitterObj.getOAuth().getOAuthTokenKey(myOAuthAccessTokenKey);
			twitterObj.getOAuth().getOAuthTokenSecret(myOAuthAccessTokenSecret);

			/* Step 6: Save these keys in a file or wherever */
			std::ofstream oAuthTokenKeyOut;
			std::ofstream oAuthTokenSecretOut;

			oAuthTokenKeyOut << myOAuthAccessTokenKey.c_str();
			oAuthTokenSecretOut << myOAuthAccessTokenSecret.c_str();

			oAuthTokenKeyOut.close();
			oAuthTokenSecretOut.close();
		}
		/* OAuth flow ends */

		/* Account credentials verification */
		if (twitterObj.accountVerifyCredGet())
		{
			twitterObj.getLastWebResponse(replyMsg);
			printf("\ntwitterClient:: twitCurl::accountVerifyCredGet web response:\n%s\n", replyMsg.c_str());
		}
		else
		{
			twitterObj.getLastCurlError(replyMsg);
			printf("\ntwitterClient:: twitCurl::accountVerifyCredGet error:\n%s\n", replyMsg.c_str());
		}

		/* Get user timeline */
		replyMsg = "";
		printf("\nGetting user timeline\n");
		if (twitterObj.timelineUserGet(true, false, 1, screenName))
		{
			twitterObj.getLastWebResponse(replyMsg);
			printf("\ntwitterClient:: twitCurl::timelineUserGet web response:\n%s\n", replyMsg.c_str());
		}
		else
		{
			twitterObj.getLastCurlError(replyMsg);
			printf("\ntwitterClient:: twitCurl::timelineUserGet error:\n%s\n", replyMsg.c_str());
		}
	}
}