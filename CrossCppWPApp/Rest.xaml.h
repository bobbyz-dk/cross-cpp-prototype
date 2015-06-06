//
// Rest.xaml.h
// Declaration of the Rest class
//

#pragma once

#include "Rest.g.h"
#include "RestApi.h"

namespace CrossCppWPApp2
{
	using namespace RestApiSpace;

	/// <summary>
	/// A basic page that provides characteristics common to most applications.
	/// </summary>
	public ref class Rest sealed
	{
	public:
		Rest();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		RestApi* rest;
		void btnPost_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btnGet_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};

}
