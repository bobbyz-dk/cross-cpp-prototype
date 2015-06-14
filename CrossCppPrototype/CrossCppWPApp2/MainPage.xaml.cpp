//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Text.h"

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
using namespace Windows::Storage;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();
	string sqliteFilename = "/TextDB.db";
	std::wstring wsLocalPath(ApplicationData::Current->LocalFolder->Path->Data());
	std::string localPath(wsLocalPath.begin(), wsLocalPath.end());
	textDao = new TextDao(localPath + sqliteFilename);
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter

	// TODO: Prepare page for display here.

	// TODO: If your application contains multiple pages, ensure that you are
	// handling the hardware Back button by registering for the
	// Windows::Phone::UI::Input::HardwareButtons.BackPressed event.
	// If you are using the NavigationHelper provided by some templates,
	// this event is handled for you.
	FillList();
}

void MainPage::FillList()
{
	vector<Text*> values = textDao->findAll();
	Platform::Collections::Vector<String^>^ itemsList = ref new Platform::Collections::Vector<String^>();
	for (vector<Text*>::iterator it = values.begin(); it < values.end(); ++it)
	{
		Text *row = *it;

		//std::wstring wid_str = std::wstring(row->getText().begin(), row->getText().end());
		std::string str = row->getText();
		std::wstring wid_str = std::wstring(str.begin(), str.end());
		const wchar_t* w_char = wid_str.c_str();
		Platform::String^ p_string = ref new Platform::String(w_char);
		itemsList->Append(p_string);
	}
	lvTexts->ItemsSource = itemsList;
}

void MainPage::btnInsert_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	std::wstring ws(txtText->Text->Data());
	std::string str(ws.begin(), ws.end());

	Text *text = new Text(str);
	textDao->insert(text);
	OutputDebugString(L"Text inserted.");
	FillList();
}
