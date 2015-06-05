//
// Twitter.xaml.h
// Declaration of the Twitter class
//

#pragma once

#include "Twitter.g.h"

namespace CrossCppWPApp
{

	/// <summary>
	/// A basic page that provides characteristics common to most applications.
	/// </summary>
	public ref class Twitter sealed
	{
	public:
		Twitter();


	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		void btnRetrieveTweet_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};

}
