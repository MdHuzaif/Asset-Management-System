<?php
include_once 'blade/view.searchEmail.blade.inc';
include_once COMMON.'class.common.inc';
?>

<link rel="stylesheet" href="./resources/css/sidebarStyle.css">

<div class="container">

    <!--Sidebar-->
    <div class="col-md-3">
      <nav class="navbar navbar-default sidebar" role="navigation">
        <div class="container-fluid">
            <div class="navbar-header mySideNav">
                <span><strong style="font-size: large"><img src="./resources/img/filter.png" alt="Icon" height = "40" weight ="40" class="myImg">Filter</strong></span>
                <!--Responsive-->
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-sidebar-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
            </div>
            <div class="collapse navbar-collapse" id="bs-sidebar-navbar-collapse-1">

                    <!--firstname-->
                    <ul class="nav navbar-nav">
                        <li class="mySideNavList" >&nbsp firstName<span class="pull-right"><input type="checkbox" name="cbname" id="cbname"<?php
                                if (isset($_POST['search'])&&isset($_POST['name'])&&!empty($_POST['name'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li><br>

                    <!--lastName-->
                    <ul class="nav navbar-nav">
                        <li class="mySideNavList" >&nbsp lastName<span class="pull-right"><input type="checkbox" name="cblastName" id="cblastName"<?php
                                if (isset($_POST['search'])&&isset($_POST['lastName'])&&!empty($_POST['lastName'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li><br>




                    <!--Email -->
                    <ul class="nav navbar-nav">
                        <li class="mySideNavList" >&nbsp email<span class="pull-right"><input type="checkbox" name="cbemail" id="cbemail"<?php
                                if (isset($_POST['search'])&&isset($_POST['email'])&&!empty($_POST['email'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li><br>



                    <!--contact -->
                    <ul class="nav navbar-nav">
                        <li class="mySideNavList" >&nbsp contact<span class="pull-right"><input type="checkbox" name="cbcontact" id="cbcontact"<?php
                                if (isset($_POST['search'])&&isset($_POST['contact'])&&!empty($_POST['contact'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li><br>




                    <!--contactEmail -->
                    <ul class="nav navbar-nav">
                        <li class="mySideNavList" >&nbsp contactEmail<span class="pull-right"><input type="checkbox" name="cbcontactEmail" id="cbcontactEmail"<?php
                                if (isset($_POST['search'])&&isset($_POST['contactEmail'])&&!empty($_POST['contactEmail'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li><br>



                    <!--address -->
                    <ul class="nav navbar-nav">
                        <li class="mySideNavList" >&nbsp address<span class="pull-right"><input type="checkbox" name="cbaddress" id="cbaddress"<?php
                                if (isset($_POST['search'])&&isset($_POST['address'])&&!empty($_POST['address'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li><br>




                    <!--CreatedAt-->
                    <li class="mySideNavList" >&nbsp CreatedAt<span class="pull-right"><input type="checkbox" name="cbcreated_at" id="cbcreated_at"<?php
                            if (isset($_POST['search'])&&isset($_POST['created_at'])&&!empty($_POST['created_at'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>

                        <!--ExpireAt-->
                        <li class="mySideNavList" >&nbsp ExpireAt<span class="pull-right"><input type="checkbox" name="cbexpire_at" id="cbexpire_at"<?php
                                if (isset($_POST['search'])&&isset($_POST['expire_at'])&&!empty($_POST['expire_at'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li>

                </ul>
            </div>
        </div>
    </nav>
    </div>

    <!--Search Div-->
    <div class="col-md-9">
        <div class="panel panel-default myPanel">

            <div class="panel-heading myHeading">
                <strong><img src="./resources/img/searchProject.png" alt="Icon" height="40" weight ="40" class="myImg">&nbsp;Search Email</strong>
            </div>

            <div class="panel-body form-horizontal">

                <!--Search Form-->
                <form method="post" class="form-horizontal">

                    <!--firstName-->
                    <div id="divname" class="form-group" hidden >
                        <label for="name" class="control-label col-md-3">firstName :</label>
                        <div class="col-md-7">
                            <input type="text" name="name" id="name" class="form-control" placeholder="firstName" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['name'])) {
                                echo $_POST['name'];
                            }
                            ?>" required>
                        </div>
                    </div>

                    <!--lastName-->
                    <div id="divlastName" class="form-group" hidden >
                        <label for="lastName" class="control-label col-md-3">lastName :</label>
                        <div class="col-md-7">
                            <input type="text" name="lastName" id="lastName" class="form-control" placeholder="lastName" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['lastName'])) echo $_POST['lastName'];
                            ?>" required>
                        </div>
                    </div>


                     <!--Email-->
                    <div id="divemail" class="form-group" hidden >
                        <label for="email" class="control-label col-md-3">Email :</label>
                        <div class="col-md-7">
                            <input type="text" name="email" id="email" class="form-control" placeholder="Email" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['email'])) echo $_POST['email'];
                            ?>" required>
                        </div>
                    </div>



                    <!--contact  -->
                    <div id="divcontact" class="form-group" hidden >
                        <label for="contact" class="control-label col-md-3">Contact :</label>
                        <div class="col-md-7">
                            <input type="text" name="contact" id="contact" class="form-control" placeholder="Contact" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['contact'])) echo $_POST['contact'];
                            ?>" required>
                        </div>
                    </div>


                    <!--contactEmail  -->
                    <div id="divcontactEmail" class="form-group" hidden >
                        <label for="contactEmail" class="control-label col-md-3">contactEmail :</label>
                        <div class="col-md-7">
                            <input type="text" name="contactEmail" id="contactEmail" class="form-control" placeholder="contactEmail" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['contactEmail'])) echo $_POST['contactEmail'];
                            ?>" required>
                        </div>
                    </div>



                     <!--address-->
                    <div id="divaddress" class="form-group" hidden >
                        <label for="address" class="control-label col-md-3">address :</label>
                        <div class="col-md-7">
                            <input type="text" name="address" id="address" class="form-control" placeholder="address" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['address'])) echo $_POST['address'];
                            ?>" required>
                        </div>
                    </div>




                
                    <!--CreatedAt -->
                    <div id="divcreated_at" class="form-group" hidden>
                        <label for="created_at" class="control-label col-md-3">Created_at :</label>
                        <div class="col-md-7">
                            <input type="date" name="created_at" id="created_at" class="form-control" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['created_at'])) echo $_POST['created_at'];
                            ?>" required>
                        </div>
                    </div>

                    <!--Expire_at -->
                    <div id="divexpire_at" class="form-group" hidden>
                        <label for="expire_at" class="control-label col-md-3">Expire_at :</label>
                        <div class="col-md-7">
                            <input type="date" name="expire_at" id="expire_at" class="form-control" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['expire_at'])) echo $_POST['expire_at'];
                            ?>" required>
                        </div>
                    </div>




                    <br>

                    <!--Search Button-->
                    <div class="form-group">
                        <input type="submit" name="search" id="search" class="btn btn-primary col-md-2 col-md-offset-5" value="Search">
                    </div>
                </form>

            </div>
        </div>
    </div>
</div>

<!--Display Search Results-->


<?php
$Email = new Email();


$Email->setEmailFirstName($_DB->secureInput($_POST['name']));
$Email->setEmailLastName($_DB->secureInput($_POST['lastName']));
$Email->setEmailEmail($_DB->secureInput($_POST['email']));
$Email->setEmailContact($_DB->secureInput($_POST['contact']));
$Email->setEmailContactEmail($_DB->secureInput($_POST['contactEmail']));
$Email->setEmailAddress($_DB->secureInput($_POST['address']));
$Email->setEmailCreatedAt($_DB->secureInput($_POST['created_at']));
$Email->setEmailExpireAt($_DB->secureInput($_POST['expire_at']));
$Result = $_EmailBao->searchEmail($Email);


if ($Result) {
?>

    <div class="col-md-12">
        <div class="panel panel-table">
            <table class="table table-striped table-bordered table-responsive">
                <!--Header Row-->
                <tr>
                    <th>firstName</th>
                    <th>lastName</th>
                    <th>email</th>
                    <th>contact</th>
                    <th>contactEmail</th>
                    <th>address</th>
                    <th>created_at</th>
                    <th>expire_at</th>
                </tr>

                <!--Table Cells-->
                <?php

                if (!$Result->getIsSuccess()) {
                    echo 'No result found';
                } else {
                    $EmailList = $Result->getResultObject();
                    foreach ($EmailList as $email) {
                        ?>
                        <tr>
                            <td><?php echo $email->getEmailFirstName(); ?></td>
                            <td><?php echo $email->getEmailLastName(); ?></td>
                            <td><?php echo $email->getEmailEmail(); ?></td>
                            <td><?php echo $email->getEmailContact(); ?></td>
                            <td><?php echo $email->getEmailContactEmail(); ?></td>
                            <td><?php echo $email->getEmailAddress(); ?></td>
                            <td><?php echo $email->getEmailCreatedAt(); ?></td>
                            <td><?php echo $email->getEmailExpireAt(); ?></td>

                        </tr>
                        <?php
                    }
                }
                ?>
            </table>
        </div>
    </div>
<?php } ?>
<!--Script for loading searching options-->
<script>
    //Load on postback
    $(document).ready(function() {
        cbFunction();
    });

    function cbFunction() {
        //FirstName CB
        if($('#cbname').prop('checked')){
            $('#divname').show();
            $('#name').prop('required',true);
        }else {
            $('#divname').hide();
            $('#name').prop('required',false);
            $('#name').val(null);
        } 

  //FirstName CB
        if($('#cblastName').prop('checked')){
            $('#divlastName').show();
            $('#lastName').prop('required',true);
        }else {
            $('#divlastName').hide();
            $('#lastName').prop('required',false);
            $('#lastName').val(null);
        } 

         //Email CB
        if($('#cbemail').prop('checked')){
            $('#divemail').show();
            $('#email').prop('required',true);
        }else {
            $('#divemail').hide();
            $('#email').prop('required',false);
            $('#email').val(null);
        } 

        //Contact CB
        if($('#cbcontact').prop('checked')){
            $('#divcontact').show();
            $('#contact').prop('required',true);
        }else {
            $('#divcontact').hide();
            $('#contact').prop('required',false);
            $('#contact').val(null);
        } 

        //ContactEmail CB
        if($('#cbcontactEmail').prop('checked')){
            $('#divcontactEmail').show();
            $('#contactEmail').prop('required',true);
        }else {
            $('#divcontactEmail').hide();
            $('#contactEmail').prop('required',false);
            $('#contactEmail').val(null);
        } 

         //ContactEmail CB
        if($('#cbaddress').prop('checked')){
            $('#divaddress').show();
            $('#address').prop('required',true);
        }else {
            $('#divaddress').hide();
            $('#address').prop('required',false);
            $('#address').val(null);
        } 

        //Date CB
        if($('#cbcreated_at').prop('checked')){
            $('#divcreated_at').show();
            $('#created_at').prop('required',true);
        }else{
            $('#divcreated_at').hide();
            $('#created_at').prop('required',false);
            $('#created_at').val(null);
        }

        //Date CB
        if($('#cbexpire_at').prop('checked')){
            $('#divexpire_at').show();
            $('#expire_at').prop('required',true);
        }else{
            $('#divexpire_at').hide();
            $('#expire_at').prop('required',false);
            $('#expire_at').val(null);
        }


    }
</script>