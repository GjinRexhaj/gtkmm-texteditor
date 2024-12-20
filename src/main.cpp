#include <gtkmm.h>
#include <iostream>

// TODO: properly format project with "main" source file and seperate files for mainwindow

Gtk::Window* mainWindow = nullptr;
Gtk::Window* aboutWindow = nullptr;
Gtk::Window* fileChooserWindow = nullptr;
//Gtk::Window* fileSaverWindow = nullptr;

Glib::RefPtr<Gtk::Application> app;

// DEBUG VARS, REMOVE AND IMPLEMENT LATER
bool isFileOpen = false;


// declaring signal handlers
void on_info_button_clicked()
{
    std::cout<<"info button clicked"<<"\n";

    app->add_window(*aboutWindow);
    aboutWindow->set_visible(true);
    //aboutWindow->
}

void on_save_button_clicked()
{
    std::cout<<"save button clicked"<<"\n";

    // open file saver dialog if file isn't open
    if (!isFileOpen) {
        //app->add_window(*fileSaverWindow);
        //fileSaverWindow->set_visible(true);
        return;
    } else if (isFileOpen) {
        // otherwise, save to selected path
        std::cout<<"else";
        return;
    }
    std::cout<<"ERROR: Undefined Behavior";
}

void on_file_button_clicked()
{
    std::cout<<"file button clicked"<<"\n";

    /*
    auto fileChooserDialog = GTK::FileChooserNative::create("Choose file",
            *this,  Gtk::FileChooser::Action::SELECT_FOLDER,
            "Open", "Cancel");
    */
    // TODO: ditch cambalache file dialogs and manually implement them in code
    // create file chooser dialog

    //auto fileChooserDialog = Gtk::FileDialog::create();
    //fileChooserDialog->open(sigc::bind(sigc::mem_fun(
    //      *this, &mainWindow::on_file_opened), fileChooserDialog));



    // old cambalache code:
    //app->add_window(*fileChooserWindow);
    //fileChooserWindow->set_visible(true);
}

void on_file_opened() {
    std::cout<<"file opened";
}

// APP SETUP
void on_app_activate()
{

  // Load UI file into gtk:builder and instantiate
  auto builder = Gtk::Builder::create();
  builder->add_from_file("src/ui/gtk-texteditor.ui");

  // set mainWindow to point to top-level widget of UI file
  mainWindow = builder->get_widget<Gtk::Window>("mainWindow");
  aboutWindow = builder->get_widget<Gtk::Window>("aboutWindow");

  //fileChooserWindow = builder->get_widget<Gtk::Window>("fileOpenerWindow");
  //fileSaverWindow = builder->get_widget<Gtk::Window>("fileSaverWindow");


  // CONNECT SIGNALS AND SLOTS
  auto aboutButton = builder->get_widget<Gtk::Button>("about_button");
  if (aboutButton){
      aboutButton->signal_clicked().connect([] () { on_info_button_clicked(); });
  }

  auto fileButton = builder->get_widget<Gtk::Button>("file_button");
  if (fileButton){
      fileButton->signal_clicked().connect([] () { on_file_button_clicked(); });
  }

  auto saveButton = builder->get_widget<Gtk::Button>("save_button");
  if (saveButton){
      saveButton->signal_clicked().connect([] () { on_save_button_clicked(); });
  }


  // add to Application window and set visible
  app->add_window(*mainWindow);
  mainWindow->set_visible(true);
}


// main method - launching point of the application
int main(int argc, char** argv)
{
  app = Gtk::Application::create();
  app->signal_activate().connect([] () { on_app_activate(); });
  return app->run(argc, argv);
}
