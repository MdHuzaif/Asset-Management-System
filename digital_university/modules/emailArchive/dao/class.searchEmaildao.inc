<!--Search specific Email-->
<?php
// write dao object for each class
include_once COMMON.'class.common.email.inc';
include_once UTILITY.'class.util.inc';

Class SearchEmailDao
{
    private $_DB;
    private $_Email;
    private $_Student;

    public function __construct()
    {
        $this->_DB=DBUtil::getInstance();
        $this->_Email=new Email();
        $this->_Student=new User();
    }

    //Get Searched Email
    public function getSearchedEmail($email){

        $SQL="SELECT * FROM ems_email WHERE email LIKE '%$email%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }



    //Get Searched Firstname
    public function getSearchedFirstName($firstname){

        $SQL="SELECT * FROM ems_email WHERE firstname LIKE '%$firstname%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }


    //Get Searched LastName
    public function getSearchedLastName($lastname){

        $SQL="SELECT * FROM ems_email WHERE lastname LIKE '%$lastname%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }

    //Get Searched contact
    public function getSearchedContact($contact){

        $SQL="SELECT * FROM ems_email WHERE contact LIKE '%$contact%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }

//Get Searched contactEmail
    public function getSearchedContactEmail($contactEmail){

        $SQL="SELECT * FROM ems_email WHERE contactEmail LIKE '%$contactEmail%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }

    //Get Searched address
    public function getSearchedAddress($address){

        $SQL="SELECT * FROM ems_email WHERE address LIKE '%$address%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }

//Get Searched created_at
    public function getSearchedCreated_at($created_at){

        $SQL="SELECT * FROM ems_email WHERE created_at LIKE '%$created_at%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }
//Get Searched Expire_at
    public function getSearchedExpire_at($expire_at){

        $SQL="SELECT * FROM ems_email WHERE expire_at LIKE '%$expire_at%';";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        $EmailList = [];
        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;

        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);
        return $Result;
    }


}
?>
