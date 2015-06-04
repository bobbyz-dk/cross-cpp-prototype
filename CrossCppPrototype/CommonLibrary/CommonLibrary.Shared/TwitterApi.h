#include <stdio.h>
#include <string>

namespace twitter
{
	using namespace std;

	class TwitterApi {

	public:
		TwitterApi();
		~TwitterApi();

		string LoadLastTweet(string screenName);
	};
}