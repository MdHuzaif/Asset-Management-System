<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'bao/class.assetSearchBao.inc';
include_once MODULES_ASSET.'bao/class.assetBao.inc';

$_SearchProjectBao=new SearchAssetBao();
$_AssetBao=new AssetBao();
$_DB=DBUtil::getInstance();

// fullname
$nameSearchResult = null;
//Type
$typeSearchResult = null;

if (isset($_POST['search']) && !empty($_POST['type'])) {
    $name = $_POST['type'];
    $typeSearchResult = $_SearchProjectBao->getSearchedType($type);
}

?>

