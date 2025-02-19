using Lab10.Models;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.Security.Claims;

namespace Lab10.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index(IFormCollection form)
        {
            string user = form["username"].ToString();
            string password = form["password"].ToString();
            ClaimsIdentity identity = null;
            bool isAuthenticated = false;
            if (user == "admin" && password == "admin") {
                identity = new ClaimsIdentity(new[]
                {
                    new Claim(ClaimTypes.Name, user),
                    new Claim(ClaimTypes.Role, "Admin")
                },
                CookieAuthenticationDefaults.AuthenticationScheme);
                isAuthenticated = true;
            }
            if (isAuthenticated)
            {
                var principle = new ClaimsPrincipal(identity);
                var login = HttpContext.SignInAsync(CookieAuthenticationDefaults.AuthenticationScheme, principle);
                return RedirectToAction("Common", "Home");
            }

            return View();
        }
        //common action
        public IActionResult Common()
        {
            return View();
        }
        [Authorize (Roles ="Admin")]
        public IActionResult Home()
        {
            return View();
        }
        [Authorize (Roles ="User")]
        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
        

    }
}
