<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_EMAIL.'bao/class.searchEmailbao.inc';
include_once MODULES_EMAIL.'bao/class.emailbao.inc';

$_SearchEmailBao=new SearchEmailBao();
$_EmailBao=new EmailBao();
$_DB=DBUtil::getInstance();
// fullname
    $nameSearchResult = null;
//firstname
            $firstNameSearchResult = null;

            if (isset($_POST['search']) && !empty($_POST['name'])) {
                $name = $_POST['name'];
                $name = str_replace("%", "", $name);
                $firstNameSearchResult = $_SearchEmailBao->getSearchedFirstName($name);
            }
//lastname

            $lastNameSearchResult = null;

            if (isset($_POST['search']) && !empty($_POST['lastName'])) {
                $lastName = $_POST['lastName'];
                $lastName = str_replace("%", "", $lastName);
                $lastNameSearchResult = $_SearchEmailBao->getSearchedLastName($lastName);
             //   var_dump($lastNameSearchResult);
            }
//email

            $emailSearchResult = null;

            if (isset($_POST['search']) && !empty($_POST['email'])) {
                $email = $_POST['email'];
                $email = str_replace("%", "", $email);
                $emailSearchResult = $_SearchEmailBao->getSearchedemail($email);
                //   var_dump($lastNameSearchResult);
            }
//contact

            $contactSearchResult = null;

            if (isset($_POST['search']) && !empty($_POST['contact'])) {
                $contact = $_POST['contact'];
                $contact = str_replace("%", "", $contact);
                $contactSearchResult = $_SearchEmailBao->getSearchedcontact($contact);
                //   var_dump($lastNameSearchResult);
            }

//contactEmail

$contactEmailSearchResult = null;

if (isset($_POST['search']) && !empty($_POST['contactEmail'])) {
    $contactEmail = $_POST['contactEmail'];
    $contactEmail = str_replace("%", "", $contactEmail);
    $contactEmailSearchResult = $_SearchEmailBao->getSearchedcontactEmail($contactEmail);
    //   var_dump($lastNameSearchResult);
}

//address

$addressSearchResult = null;

if (isset($_POST['search']) && !empty($_POST['address'])) {
    $address = $_POST['address'];
    $address = str_replace("%", "", $address);
    $addressSearchResult = $_SearchEmailBao->getSearchedAddress($address);
    //   var_dump($lastNameSearchResult);
}

//created_at

$created_atSearchResult = null;

if (isset($_POST['created_at']) && !empty($_POST['created_at'])) {
    $created_at = $_POST['created_at'];
    $created_at = str_replace("%", "", $created_at);
    $created_atSearchResult = $_SearchEmailBao->getSearchedCreated_at($created_at);
    //   var_dump($lastNameSearchResult);
}

//expire_at

$expire_atSearchResult = null;

if (isset($_POST['expire_at']) && !empty($_POST['expire_at'])) {
    $expire_at = $_POST['expire_at'];
    $expire_at = str_replace("%", "", $expire_at);
    $expire_atSearchResult = $_SearchEmailBao->getSearchedExpire_at($expire_at);
    //   var_dump($lastNameSearchResult);
}


?>

