//
// Rest.xaml.cpp
// Implementation of the Rest class
//

#include "pch.h"
#include "Rest.xaml.h"

using namespace CrossCppWPApp2;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=390556

Rest::Rest()
{
	InitializeComponent();

	rest = new RestApi();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.
/// This parameter is typically used to configure the page.</param>
void Rest::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter
}


void CrossCppWPApp2::Rest::btnPost_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	std::wstring wsText(txtComment->Text->Data());
	std::string strText(wsText.begin(), wsText.end());
	std::wstring wsEmail(txtEmail->Text->Data());
	std::string strEmail(wsEmail.begin(), wsEmail.end());

	Comment comment = Comment(strText, strEmail);
	rest->PostComment(comment);
	OutputDebugStringW(L"Comment posted!\n");
}


void CrossCppWPApp2::Rest::btnGet_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	OutputDebugStringW(L"Comments retrieved!\n");
}
