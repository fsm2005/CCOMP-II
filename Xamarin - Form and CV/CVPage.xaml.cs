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

            PhoneLabel.Text = "Teléfono: +51 940 055 880";
            LocationLabel.Text = "Ubicación:Arequipa, Perú";
            LanguageLabel.Text = "Inglés: Avanzado";
            SkillsLabel.Text = "Liderazgo, Trabajo en equipo, Resolución de problemas";
            BirthdateLabel.Text = "19 de julio de 2005";
            AbilitiesLabel.Text = "C++, Python, HTML, CSS";

            ProfileDescriptionLabel.Text = "Soy un profesional enfocado en el desarrollo de software con experiencia en proyectos móviles y web.";
            ProgrammingLanguagesLabel.Text = "C#, JavaScript, SQL";
        }
    }
}
