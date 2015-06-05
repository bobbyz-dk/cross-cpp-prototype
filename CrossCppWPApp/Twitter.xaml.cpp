//
// Twitter.xaml.cpp
// Implementation of the Twitter class
//

#include "pch.h"
#include "Twitter.xaml.h"

using namespace CrossCppWPApp;

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Basic Page item template is documented at http://go.microsoft.com/fwlink/?LinkID=390556

Twitter::Twitter()
{
	InitializeComponent();
}


/// The methods provided in this section are simply used to allow
/// NavigationHelper to respond to the page's navigation methods.
/// 
/// Page specific logic should be placed in event handlers for the  
/// <see cref="NavigationHelper::LoadState"/>
/// and <see cref="NavigationHelper::SaveState"/>.
/// The navigation parameter is available in the LoadState method 
/// in addition to page state preserved during an earlier session.

void Twitter::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter
}

void CrossCppWPApp::Twitter::btnRetrieveTweet_Click(Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	/*string str = dynamic_cast<LastTweetLoadedEvent*>(evnt)->getTweet();
	wstring wid_str = wstring(str.begin(), str.end());
	const wchar_t* w_char = wid_str.c_str();
	Platform::String^ p_string = ref new Platform::String(w_char);
	lblResult->Text = p_string;*/
}
