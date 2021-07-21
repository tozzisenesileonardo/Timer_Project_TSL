#include <wx/wx.h>
#include <iostream>
using namespace std;
class Simple : public wxFrame{
public:
    Simple(const wxString& title)
            : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize( 250, 150))

    {
        Centre();
    }
};

class MyApp : public wxApp{
    bool OnInit(){
        cout<<"Hello World";
        Simple *simple = new Simple(wxT("simple"));
        simple->Show(true);
        return true;
    }
};


wxIMPLEMENT_APP(MyApp);