using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace WebApplication1.Pages
{
    public class calculateModel : PageModel
    {
        public string Title;
        [BindProperty]
        public int Num1 { get; set; }
        [BindProperty]
        public int Num2 { get; set; }

        public int Result;
        public void OnGet()
        {
            Title = "Hii there";
        }
        public void OnPost()
        {
            Result = Num1 + Num2;
        }
    }
}
