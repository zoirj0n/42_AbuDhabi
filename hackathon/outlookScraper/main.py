from webbot import Browser

web = Browser();
web.go_to('https://signin.intra.42.fr/users/sign_in');
web.type('zosobiro', into='USERNAME')
web.type('Z@irj0n5505@', into='PASSWORD')
