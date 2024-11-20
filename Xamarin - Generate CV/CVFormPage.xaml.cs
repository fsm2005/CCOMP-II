using Xamarin.Forms;

namespace YourNamespace
{
    public partial class CVFormPage : ContentPage
    {
        public CVFormPage()
        {
            InitializeComponent();
        }

        private async void OnAcceptClicked(object sender, EventArgs e)
        {
            var cvData = new CVData
            {
                Name = NameEntry.Text,
                Occupation = OccupationEntry.Text,
                Phone = PhoneEntry.Text,
                Location = LocationEntry.Text,
                Language = LanguageEntry.Text,
                Skills = SkillsEditor.Text,
                Birthdate = BirthdatePicker.Date.ToString("d MMMM yyyy"),
                Abilities = AbilitiesEditor.Text,
                ProfileDescription = ProfileDescriptionEditor.Text,
                ProgrammingLanguages = ProgrammingLanguagesEditor.Text
            };
            var cvPage = new CVPage();
            cvPage.FillCV(cvData);
            await Navigation.PushAsync(cvPage);
        }
    }
    public class CVData
    {
        public string Name { get; set; }
        public string Occupation { get; set; }
        public string Phone { get; set; }
        public string Location { get; set; }
        public string Language { get; set; }
        public string Skills { get; set; }
        public string Birthdate { get; set; }
        public string Abilities { get; set; }
        public string ProfileDescription { get; set; }
        public string ProgrammingLanguages { get; set; }
    }
}
