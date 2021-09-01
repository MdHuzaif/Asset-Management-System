<?php
include_once 'blade/view.assetSearch.blade.inc';
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

                    <!--AssetType-->
                    <ul class="nav navbar-nav">
                        <li class="mySideNavList" >&nbsp AssetType<span class="pull-right"><input type="checkbox" name="cbtype" id="cbtype"<?php
                                if (isset($_POST['search'])&&isset($_POST['type'])&&!empty($_POST['type'])){
                                    ?>
                                    checked="checked"
                                    <?php
                                }
                                ?> onchange="cbFunction();"></span></li><br>

                        <!--model No-->
                        <ul class="nav navbar-nav">
                            <li class="mySideNavList" >&nbsp ModelNo<span class="pull-right"><input type="checkbox" name="cbmodel" id="cbmodel"<?php
                                    if (isset($_POST['search'])&&isset($_POST['model'])&&!empty($_POST['model'])){
                                        ?>
                                        checked="checked"
                                        <?php
                                    }
                                    ?> onchange="cbFunction();"></span></li><br>




                            <!--Status -->
                            <ul class="nav navbar-nav">
                                <li class="mySideNavList" >&nbsp Status<span class="pull-right"><input type="checkbox" name="cbstatus" id="cbstatus"<?php
                                        if (isset($_POST['search'])&&isset($_POST['status'])&&!empty($_POST['status'])){
                                            ?>
                                            checked="checked"
                                            <?php
                                        }
                                        ?> onchange="cbFunction();"></span></li><br>



                                <!--cost -->
                                <ul class="nav navbar-nav">
                                    <li class="mySideNavList" >&nbsp Cost<span class="pull-right"><input type="checkbox" name="cbcost" id="cbcost"<?php
                                            if (isset($_POST['search'])&&isset($_POST['cost'])&&!empty($_POST['cost'])){
                                                ?>
                                                checked="checked"
                                                <?php
                                            }
                                            ?> onchange="cbFunction();"></span></li><br>


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
                    <div id="divtype" class="form-group" hidden >
                        <label for="type" class="control-label col-md-3">Asset Type :</label>
                        <div class="col-md-7">
                            <input type="text" name="type" id="type" class="form-control" placeholder="assetType" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['type'])) {
                                echo $_POST['type'];
                            }
                            ?>" required>
                        </div>
                    </div>

                    <!-- modelNo -->
                    <div id="divmodel" class="form-group" hidden >
                        <label for="model" class="control-label col-md-3">Model No :</label>
                        <div class="col-md-7">
                            <input type="text" name="model" id="model" class="form-control" placeholder="model" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['model'])) echo $_POST['model'];
                            ?>" required>
                        </div>
                    </div>


                    <!--Status-->
                    <div id="divstatus" class="form-group" hidden >
                        <label for="status" class="control-label col-md-3">Email :</label>
                        <div class="col-md-7">
                            <input type="text" name="status" id="status" class="form-control" placeholder="Status" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['status'])) echo $_POST['status'];
                            ?>" required>
                        </div>
                    </div>



                    <!--contact  -->
                    <div id="divcost" class="form-group" hidden >
                        <label for="cost" class="control-label col-md-3">Cost :</label>
                        <div class="col-md-7">
                            <input type="text" name="cost" id="cost" class="form-control" placeholder="Cost" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['cost'])) echo $_POST['cost'];
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
if (isset($_POST['search'])&&(!empty($_POST['name_id'])||!empty($_POST['lastnNme_id']))){
    ?>
    <div class="col-md-12">
        <hr>
    </div>
    <div class="col-md-12">
        <div class="panel panel-table">
            <table class="table table-striped table-bordered table-responsive">
                <!--Header Row-->
                <tr>
                    <th>firstName</th>
                    <th>lastName</th>
                    <!--    <th>email</th>
                            <th>contact</th>
                            <th>contactEmail</th>
                            <th>address</th>
                            <th>created_at</th>

                             -->

                </tr>

                <!--Table Cells-->
                <?php
                $Result=$_SearchEmailBao->getSearchedEmail();
                if($Result->getIsSuccess()){
                    $EmailList=$Result->getResultObject();

                    foreach ($EmailList as $email) {
                        ?>
                        <tr>
                            <td><a href="email_member.php?id=<?php echo $email->getEmailId();?>"><img src="<?php echo $email->getEmailFirstName();?>" alt="Icon" height="40" weight = "40" class="table-img"><?php
                                    echo ' '.$email->getEmailFirstName(); ?></a></td>



                        </tr>
                        <?php
                    }
                }
                ?>
            </table>
        </div>
    </div>
    <?php
}
?>

<?php
//$EmailList = null;
//$isCheck = false;
//
//if ($nameSearchResult != null && $nameSearchResult->getIsSuccess()) {
//    $EmailList = $nameSearchResult->getResultObject();
//    $isCheck = true;
//} else if ($firstNameSearchResult != null && $firstNameSearchResult->getIsSuccess()) {
//    $EmailList = $firstNameSearchResult->getResultObject();
//    $isCheck = true;
//} else if ($lastNameSearchResult != null && $lastNameSearchResult->getIsSuccess()) {
//    $EmailList = $lastNameSearchResult->getResultObject();
//    $isCheck = true;
//}
//else if ($emailSearchResult != null && $emailSearchResult->getIsSuccess()) {
//    $EmailList = $emailSearchResult->getResultObject();
//    $isCheck = true;
//}
//else if ($contactSearchResult != null && $contactSearchResult->getIsSuccess()) {
//    $EmailList = $contactSearchResult->getResultObject();
//    $isCheck = true;
//}
//else if ($contactEmailSearchResult != null && $contactEmailSearchResult->getIsSuccess()) {
//    $EmailList = $contactEmailSearchResult->getResultObject();
//    $isCheck = true;
//}
//else if ($addressSearchResult != null && $addressSearchResult->getIsSuccess()) {
//    $EmailList = $addressSearchResult->getResultObject();
//    $isCheck = true;
//}
//else if ($created_atSearchResult != null && $created_atSearchResult->getIsSuccess()) {
//    $EmailList = $created_atSearchResult->getResultObject();
//    $isCheck = true;
//}
//else if ($expire_atSearchResult != null && $expire_atSearchResult->getIsSuccess()) {
//    $EmailList = $expire_atSearchResult->getResultObject();
//    $isCheck = true;
//}
//?>

<?php
//if ($isCheck) {
?>

<div class="col-md-12">
    <div class="panel panel-table">
        <table class="table table-striped table-bordered table-responsive">
            <!--Header Row-->
            <tr>
                <th>type</th>
                <th>serialNo</th>
                <th>modelNo</th>
                <th>brand</th>
                <th>purchaseDate</th>
                <th>status</th>
                <th>configuration</th>
                <th>purchasedFrom</th>
                <th>cost</th>
                <th>warrantyLimit</th>
            </tr>

            <!--Table Cells-->

            <!--                        <tr>-->
            <!--                            <td>--><?php //echo $email->getEmailFirstName(); ?><!--</td>-->
            <!--                            <td>--><?php //echo $email->getEmailLastName(); ?><!--</td>-->
            <!--                            <td>--><?php //echo $email->getEmailEmail(); ?><!--</td>-->
            <!--                            <td>--><?php //echo $email->getEmailContact(); ?><!--</td>-->
            <!--                            <td>--><?php //echo $email->getEmailContactEmail(); ?><!--</td>-->
            <!--                            <td>--><?php //echo $email->getEmailAddress(); ?><!--</td>-->
            <!--                            <td>--><?php //echo $email->getEmailCreatedAt(); ?><!--</td>-->
            <!--                            <td>--><?php //echo $email->getEmailExpireAt(); ?><!--</td>-->
            <!---->
            <!--                        </tr>-->
            <?php

            ?>
        </table>
    </div>
</div>
<?php //} ?>
<!--Script for loading searching options-->
<script>
    //Load on postback
    $(document).ready(function() {
        cbFunction();
    });

    function cbFunction() {
        //Type CB
        if($('#cbtype').prop('checked')){
            $('#divtype').show();
            $('#type').prop('required',true);
        }else {
            $('#divtype').hide();
            $('#type').prop('required',false);
            $('#type').val(null);
        }

        //Model CB
        if($('#cbmodel').prop('checked')){
            $('#divmodel').show();
            $('#model').prop('required',true);
        }else {
            $('#divmodel').hide();
            $('#model').prop('required',false);
            $('#model').val(null);
        }

        //Status CB
        if($('#cbstatus').prop('checked')){
            $('#divstatus').show();
            $('#status').prop('required',true);
        }else {
            $('#divstatus').hide();
            $('#status').prop('required',false);
            $('#status').val(null);
        }

        //Cost CB
        if($('#cbcost').prop('checked')){
            $('#divcost').show();
            $('#cost').prop('required',true);
        }else {
            $('#divcost').hide();
            $('#cost').prop('required',false);
            $('#cost').val(null);
        }

    }
</script>