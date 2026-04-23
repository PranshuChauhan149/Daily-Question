select p.firstName,p.lastName,a.city,a.state from person as p LEFT JOIN address 
as a on p.personId = a.personId;