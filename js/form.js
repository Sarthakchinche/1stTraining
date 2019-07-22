$(document).ready(function(){
	$("#butt").click(function(){
		name = $("#name").val();
		mail = $("#mail").val();
		pass = $("#pass").val();
		repass = $("#repass").val();
		var res = false;
		if (name!="") {
			console.log("enter sabkuch");
			if (mail != "") {
				if (pass.length >= 8) {
					if (pass == repass) {
						alert("Successful");
						res=true;
					} else {
						alert("password does not match");
					}
				} else {
					alert("Password Length should be greater than 8 characters");
				}
			} else {
				alert("The EMAIL field should not be empty.")
			}
		} else {
			alert("Name should not be empty");
		}
		return res;

	})
});
