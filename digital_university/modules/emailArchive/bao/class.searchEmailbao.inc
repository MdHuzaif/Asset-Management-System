<!--Search specific thesis-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_EMAIL.'dao/class.searchEmaildao.inc';

/*
	User Business Object
*/
Class SearchEmailBao
{

    private $_SearchEmailDao;

    public function __construct()
    {
        $this->_SearchEmailDao=new SearchEmailDao();
    }
    //get searched Email

    public function getSearchedEmail($email){
        $Result=$this->_SearchEmailDao->getSearchedEmail($email);
        return $Result;
    }



    //get searched firstname

    public function getSearchedFirstName($firstname){
        $Result=$this->_SearchEmailDao->getSearchedFirstName($firstname);
        return $Result;
    }

    //get searched lastname

    public function getSearchedLastName($lastname){
        $Result=$this->_SearchEmailDao->getSearchedLastName($lastname);
        // var_dump($Result);
        return $Result;
    }

    //get searched contact

    public function getSearchedContact($contact){
        $Result=$this->_SearchEmailDao->getSearchedContact($contact);
        return $Result;
    }

    //get searched contactEmail

    public function getSearchedContactEmail($contactEmail){
        $Result=$this->_SearchEmailDao->getSearchedContactEmail($contactEmail);
        return $Result;
    }

    //get searched address

    public function getSearchedAddress($address){
        $Result=$this->_SearchEmailDao->getSearchedAddress($address);
        return $Result;
    }

    //get searched created_at

    public function getSearchedCreated_at($created_at){
        $Result=$this->_SearchEmailDao->getSearchedCreated_at($created_at);
        return $Result;
    }

    //get searched expire_at

    public function getSearchedExpire_at($expire_at){
        $Result=$this->_SearchEmailDao->getSearchedExpire_at($expire_at);
        return $Result;
    }


}
?>
