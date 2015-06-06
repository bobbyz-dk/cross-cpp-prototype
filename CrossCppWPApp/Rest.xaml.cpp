//
// Rest.xaml.cpp
// Implementation of the Rest class
//

#include "pch.h"
#include "Rest.xaml.h"

using namespace CrossCppWPApp2;
using namespace RestApiSpace;

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

Rest::Rest()
{
	InitializeComponent();

	rest = new RestApi();
}

void Rest::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void)e;	// Unused parameter
}

void CrossCppWPApp::Rest::btnPost_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	std::wstring wsText(txtComment->Text->Data());
	std::string strText(wsText.begin(), wsText.end());
	std::wstring wsEmail(txtEmail->Text->Data());
	std::string strEmail(wsEmail.begin(), wsEmail.end());

	Comment comment = Comment(strText, strEmail);
	rest->PostComment(comment);
}


void CrossCppWPApp::Rest::btnGet_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}
