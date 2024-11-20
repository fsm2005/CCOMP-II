using Xamarin.Forms;

namespace YourNamespace
{
    public partial class CVPage : ContentPage
    {
        public CVPage()
        {
            InitializeComponent();
        }

        public void FillCV(CVData data)
        {
            NameLabel.Text = data.Name;
            OccupationLabel.Text = data.Occupation;
            PhoneLabel.Text = $"Tel�fono: {data.Phone}";
            LocationLabel.Text = $"Ubicaci�n: {data.Location}";
            LanguageLabel.Text = data.Language;
            SkillsLabel.Text = data.Skills;
            BirthdateLabel.Text = $"Fecha de Nacimiento: {data.Birthdate}";
            AbilitiesLabel.Text = $"Habilidades: {data.Abilities}";
            ProfileDescriptionLabel.Text = data.ProfileDescription;
            ProgrammingLanguagesLabel.Text = data.ProgrammingLanguages;
        }
    }
}
