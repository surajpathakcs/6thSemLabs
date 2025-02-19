import { Component } from '@angular/core';
import { FormGroup, FormControl, Validators } from '@angular/forms';

@Component({
  standalone: false,
  selector: 'student',
  templateUrl:'./student.component.html',
})

export class StudentComponent {
  studentForm = new FormGroup({
    firstname: new FormControl("",[Validators.required])
  });
  formSubmit() {
    if (this.studentForm.valid) {
      var value = this.studentForm.get('firstname')?.value;
      alert(value);
    } else
    {
      alert("Please fill the form")
    }
  }

  get Firstname(): FormControl {
    return this.studentForm.get('firstname') as FormControl;
  }
}
