using Xamarin.Forms;

namespace YourNamespace
{
    public partial class CVPage : ContentPage
    {
        public CVPage()
        {
            InitializeComponent();
            LoadData();
        }

        private void LoadData()
        {
            ProfileImage.Source = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSLcL-pGtcCFU06xfdcCWHA7gL48jPnxaIEGA&amp";
            NameLabel.Text = "Fabricio Stelman Melo";
            OccupationLabel.Text = "Ciencia de la computacion";

            PhoneLabel.Text = "Tel�fono: +51 940 055 880";
            LocationLabel.Text = "Ubicaci�n:Arequipa, Per�";
            LanguageLabel.Text = "Ingl�s: Avanzado";
            SkillsLabel.Text = "Liderazgo, Trabajo en equipo, Resoluci�n de problemas";
            BirthdateLabel.Text = "19 de julio de 2005";
            AbilitiesLabel.Text = "C++, Python, HTML, CSS";

            ProfileDescriptionLabel.Text = "Soy un profesional enfocado en el desarrollo de software con experiencia en proyectos m�viles y web.";
            ProgrammingLanguagesLabel.Text = "C#, JavaScript, SQL";
        }
    }
}
