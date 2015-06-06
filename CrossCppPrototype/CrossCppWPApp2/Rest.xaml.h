//
// Rest.xaml.h
// Declaration of the Rest class
//

#pragma once

#include "Rest.g.h"
#include "Comment.h"
#include "RestApi.h"

namespace CrossCppWPApp2
{
	using namespace model;
	using namespace RestApiSpace;

	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Rest sealed
	{
	public:
		Rest();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		void btnPost_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btnGet_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		RestApi* rest;
	};
}
